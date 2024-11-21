//vertex shader for no lighting
#version 410 core

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;
layout(location=2) in vec3 vColor;

//matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMatrix;

//lighting
uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 baseColor;

out vec3 color;

vec3 ambient;
float ambientStrength = 0.2f;
vec3 diffuse;

vec3 specular;
float specularStrength = 0.5f;
float shininess = 32.0f;

void main()
{		
	ambient = ambientStrength * lightColor;

	vec3 lightDirN = normalize(lightDir);
	vec3 normalEye = normalize(normalMatrix * vNormal);

	diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;

	vec4 vertPosEye = view * model * vec4(vPosition, 1.0f);
	vec3 viewDir = normalize(- vertPosEye.xyz);
	vec3 reflectDir = normalize(reflect(-lightDir, normalEye));

	float specCoeff = pow(max(dot(viewDir, reflectDir), 0.0f), shininess);
	specular = specularStrength * specCoeff * lightColor;

	color = min((ambient + diffuse) * vColor + specular, 1.0f);

	gl_Position = projection * view * model * vec4(vPosition, 1.0f);
}
