#include<stdio.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

// Window sizes
const GLint WIDTH = 800, HEIGHT = 600;

int main() {

	// Init GLFW
	if (!glfwInit()) {
		printf("GLFW initialization falied");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// No backward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// We support forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Delhion Engine - Renderer", NULL, NULL);
	if (!mainWindow) {
		printf("GLFW Window creation is failed");
		glfwTerminate();
		return 1;
	}

	// Get Buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set the context
	glfwMakeContextCurrent(mainWindow);

	// Allow modern features
	glewExperimental = GL_TRUE;

	// Init GLEW
	if (glewInit() != GLEW_OK) {
		printf("GLEW INIT FAIELD");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setup ViewPort size
	glViewport(0, 0, bufferWidth, bufferHeight);

	// LOOP 
	while (!glfwWindowShouldClose(mainWindow)) {
		// Get and handle User Input Event
		glfwPollEvents();

		// Clear Window
		glClearColor(0.2f, 0.2f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}