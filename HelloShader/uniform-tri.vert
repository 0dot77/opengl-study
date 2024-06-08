#version 330 core

in vec4 aPos;
in vec4 aColor;
uniform vec4 uMove;
out vec4 vColor;

void main(void)
{
	gl_Position = aPos + uMove;
	vColor = aColor;
}