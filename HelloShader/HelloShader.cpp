#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")

#include <stdio.h>

const char* vertSource =
"#version 330 core \n\
		in vec4 vertexPos; \n\
		void main(void) { \n\
			gl_Position = vertexPos; \n\
		}";

const char* fragSource =
"#version 330 core \n\
		out vec4 fragColor; \n\
		void main(void) { \n\
			fragColor = vec4(1.0, 0.0, 0.0, 1.0); \n\
		}";

GLuint vert = 0;
GLuint frag = 0;
GLuint prog = 0;

void initFunc(void)
{
	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vertSource, NULL);
	glCompileShader(vert);

	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragSource, NULL);
	glCompileShader(frag);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog); // Link to get .EXE 실행 가능한 형태로 구현

	glUseProgram(prog); // 실행!
}
GLfloat vertices[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

void drawFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	GLuint loc = glGetAttribLocation(prog, "vertexPos");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, vertices);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFinish();
}

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewInit();


	// main loop
	initFunc();
	while (!glfwWindowShouldClose(window))
	{
		//draw
		drawFunc();

		//GLFW actions
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
