//
//  main.cpp
//  OpenGL Transformations
//

#if defined(__APPLE__)
#define GLFW_INCLUDE_GLCOREARB
#else
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "src/Shader.hpp"

int glWindowWidth = 800;
int glWindowHeight = 600;
int retina_width, retina_height;
GLFWwindow *glWindow = NULL;

GLfloat vertices[] = {
	-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // 0
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  // 1
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,   // 2
	-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,  // 3
	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // 4
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,   // 5
	0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 1.0f,	   // 6
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,   // 7
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // 8   0'
	0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  // 9   1'
	0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // 10   2'
	-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,  // 11   3'
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // 12   4'
	0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 1.0f,   // 13   5'
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,	   // 14   6'
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,   // 15   7'
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // 16   0''
	0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,  // 17   1''
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,   // 18   2''
	-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,  // 19   3''
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  // 20   4''
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,   // 21   5''
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,	   // 22   6''
	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f,   // 23   7''
};

GLuint indices[] = {
	0, 1, 2, 0, 2, 3,		// bottom plane triangles
	8, 9, 5, 8, 5, 4,		// back plane triangles
	17, 10, 6, 17, 6, 13,	// right plane triangles
	16, 12, 7, 16, 7, 11,	// left plane triangles
	20, 21, 14, 20, 14, 15, // top plane triangles
	19, 18, 22, 19, 22, 23	// front plane triangles
};

GLuint verticesVBO;
GLuint verticesEBO;
GLuint objectVAO;

gps::Shader myCustomShader;
glm::mat4 model;
GLint modelLocation;

bool wireframeView = false;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{

		glfwSetWindowShouldClose(glWindow, GLFW_TRUE);
	}

	if (key == GLFW_KEY_T && action == GLFW_PRESS)
	{

		wireframeView = !wireframeView;

		if (wireframeView)
		{

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else
		{

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	}
}

void initObjects()
{

	glGenVertexArrays(1, &objectVAO);
	glBindVertexArray(objectVAO);

	glGenBuffers(1, &verticesVBO);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &verticesEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, verticesEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	// vertex colour attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void initScene()
{
	initObjects();
	glEnable(GL_DEPTH_TEST);

	myCustomShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.frag");
	myCustomShader.useShaderProgram();

	model = glm::mat4(1.0f);
	modelLocation = glGetUniformLocation(myCustomShader.shaderProgram, "model");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	GLint viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	glm::mat4 projection = glm::perspective(70.0f, (float)glWindowWidth / (float)glWindowHeight, 0.1f, 1000.0f);
	GLint projLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

bool initOpenGLWindow()
{

	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	// window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window scaling for HiDPI displays
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

	// for multisampling/antialising
	glfwWindowHint(GLFW_SAMPLES, 4);

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Transformations", NULL, NULL);

	if (!glWindow)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		return false;
	}

	glfwSetWindowSizeCallback(glWindow, nullptr);
	glfwSetKeyCallback(glWindow, key_callback);
	glfwMakeContextCurrent(glWindow);

#if not defined(__APPLE__)
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
#endif

	// get version info
	const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte *version = glGetString(GL_VERSION);	// version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	return true;
}

float angle = 0;
float angle2 = 0;
void renderScene()
{
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, retina_width, retina_height);

	if (glfwGetKey(glWindow, GLFW_KEY_R))
	{
		angle += 0.02f;
	}

	if (glfwGetKey(glWindow, GLFW_KEY_T))
	{
		angle2 += 0.02f;
	}

	model = glm::mat4(1.0f);
	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	myCustomShader.useShaderProgram();
	glBindVertexArray(objectVAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	// cub 2
	model = glm::translate(model, glm::vec3(-2, 0, 0));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

	model = glm::rotate(model, angle2, glm::vec3(0, 1, 0));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

	model = glm::translate(model, glm::vec3(2, 0, 0));
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
	myCustomShader.useShaderProgram();
	glBindVertexArray(objectVAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void cleanup()
{

	if (verticesVBO)
	{
		glDeleteBuffers(1, &verticesVBO);
	}

	if (verticesEBO)
	{
		glDeleteBuffers(1, &verticesEBO);
	}

	if (objectVAO)
	{
		glDeleteVertexArrays(1, &objectVAO);
	}

	glfwDestroyWindow(glWindow);
	glfwTerminate();
}

void update(GLFWwindow *window);

int main(int argc, const char *argv[])
{
	if (!initOpenGLWindow())
	{
		glfwTerminate();
		return -1;
	}

	initScene();

	update(glWindow);

	cleanup();

	return 0;
}

void update(GLFWwindow *window)
{
	while (!glfwWindowShouldClose(glWindow))
	{
		renderScene();

		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}
}
