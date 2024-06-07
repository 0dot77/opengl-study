#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")

#include <stdio.h>

GLfloat clr[4] = { 0.933f, 0.769f, 0.898f, 1.0f };

void keyFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
	case 'Q':
		clr[0] += 0.01f;
		if (clr[0] > 1.0f) clr[0] = 1.0f;
		break;
	case 'W':
		clr[1] += 0.01f;
		if (clr[1] > 1.0f) clr[1] = 1.0f;
		break;
	case 'E':
		clr[2] += 0.01f;
		if (clr[2] > 1.0f) clr[2] = 1.0f;
		break;
	case 'A':
		clr[0] -= 0.01f;
		if (clr[0] < 0.0f) clr[0] = 0.0f;
		break;
	case 'S':
		clr[1] -= 0.01f;
		if (clr[1] < 0.0f) clr[1] = 0.0f;
		break;
	case 'D':
		clr[2] -= 0.01f;
		if (clr[2] < 0.0f) clr[2] = 0.0f;
		break;
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		break;
	}
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
}

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewInit();
	glfwSetKeyCallback(window, keyFunc);
	glClearColor(clr[0], clr[1], clr[2], clr[3]);

	// main loop
	while (!glfwWindowShouldClose(window))
	{
		//draw
		glClear(GL_COLOR_BUFFER_BIT);
		glFinish();

		//GLFW actions
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
