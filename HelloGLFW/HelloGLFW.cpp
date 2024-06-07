// HelloGLFW.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")

#include <stdio.h>

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewInit();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

