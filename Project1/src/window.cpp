#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int height, int width);
void processinput(GLFWwindow* window);
const unsigned int SCR_width = 800;
const unsigned int SCR_height = 600;

int main(void)
{
	//initialiize and Configure GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creation of a window
	GLFWwindow* window = glfwCreateWindow(SCR_width, SCR_height, "HELLO", NULL, NULL);
	if (window == NULL) {
		cout << "FAILED TO CREATE A WIDNOW";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//loading all the OPEN GL FUNCTION POINTERS
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout<<"Failed to initlize GLAD";
		return -1;
	}

	//render loop
	while (!glfwWindowShouldClose(window)) {

		//input
		processinput(window);

		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//swap buffer and polling
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
//processing inputs

void processinput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//whenever window size is changed or resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}