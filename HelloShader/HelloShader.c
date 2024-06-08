#define _CRT_SECURE_NO_WARNINGS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma warning(disable: 4711 4710 4100)

#include <stdio.h>
#include "./common.h"

const char* vertFileName = "uniform-tri.vert";
const char* fragFileName = "uniform-tri.frag";

GLuint vert = 0;
GLuint frag = 0;
GLuint prog = 0;


void initFunc(void)
{
	const char* vertSource = loadFile(vertFileName);
	const char* fragSource = loadFile(fragFileName);

	char buf[1024];
	GLint status;

	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vertSource, NULL);
	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &status);
	printf("vert compile status = %s\n", (status == GL_TRUE) ? "true" : "false");
	glGetShaderInfoLog(vert, sizeof(buf), NULL, buf);
	printf("vert log = [%s]\n", buf);

	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fragSource, NULL);
	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &status);
	printf("frag compile status = %s\n", (status == GL_TRUE) ? "true" : "false");
	glGetShaderInfoLog(frag, sizeof(buf), NULL, buf);
	printf("frag log = [%s]\n", buf);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog); // Link to get .EXE 실행 가능한 형태로 구현
	glGetProgramiv(prog, GL_LINK_STATUS, &status);
	printf("prog link status = %s\n", (status == GL_TRUE) ? "true" : "false");
	glGetProgramInfoLog(prog, sizeof(buf), NULL, buf);
	printf("link log = [%s]\n", buf);

	glValidateProgram(prog);
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &status);
	printf("prog validate status = %s\n", (status == GL_TRUE) ? "true" : "false");
	glGetProgramInfoLog(prog, sizeof(buf), NULL, buf);
	printf("validate log = [%s]\n", buf);

	glUseProgram(prog); // 실행!

	//done
	free((void*)vertSource);
	free((void*)fragSource);
}
GLfloat vertPos[] = {
	-0.5f, -0.5f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.0f, 1.0f,
};

GLfloat vertColor[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
};

void drawFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// vertex attributes
	GLuint loc = glGetAttribLocation(prog, "aPos");
	glEnableVertexAttribArray(loc); // 대응 되는 레지스터를 Enable 한다.
	glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, vertPos);

	// color attributes
	loc = glGetAttribLocation(prog, "aColor");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, vertColor);

	GLuint locMove = glGetUniformLocation(prog, "uMove");
	glUniform4f(locMove, -0.5F, -0.5F, 0.0F, 0.0F);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glUniform4f(locMove, 0.0F, 0.25F, 0.0F, 0.0F);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// openGL 명령어 큐에 있는 명령어를 finish 시킨다.
	glFinish();
}

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "TEST", NULL, NULL);

	glfwMakeContextCurrent(window);

	glewInit();

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

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
