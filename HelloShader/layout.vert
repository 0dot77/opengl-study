#version 330 core

layout(location = 5) in vec4 vertPos;

void main(void)
{
	gl_Position = vertPos;
}