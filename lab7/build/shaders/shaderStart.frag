//pass-through fragment shader for OpenGL lighting
#version 410 core

in vec3 color;
out vec4 fColor;

uniform vec3 baseColor;
uniform sampler2D diffuseTexture;

void main()
{	
	fColor = vec4(color, 1.0f);
}
