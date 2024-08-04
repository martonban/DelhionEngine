#include "Window.h"


Window::Window(GLint width, GLint height) {
	m_width = width;
	m_height = height;
}

void Window::Init() {
	// Init GLFW
	if (!glfwInit()) {
		glfwTerminate();
		throw std::runtime_error("GLFW initialization falied");
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// No backward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// We support forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	Window::m_mainWindow = glfwCreateWindow(m_width, m_height, "Delhion Engine - Renderer", NULL, NULL);
	if (!m_mainWindow) {
		glfwTerminate();
		throw std::runtime_error("GLFW Window creation is failed");
	}

	// Get Buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(m_mainWindow, &bufferWidth, &bufferHeight);

	// Set the context
	glfwMakeContextCurrent(m_mainWindow);

	// Allow modern features
	glewExperimental = GL_TRUE;

	// Init GLEW
	if (glewInit() != GLEW_OK) {
		glfwDestroyWindow(m_mainWindow);
		glfwTerminate();
		throw std::runtime_error("GLEW INIT FAIELD");
	}

	// Setup ViewPort
	glViewport(0, 0, bufferWidth, bufferHeight);
}

void Window::Loop() {
	// LOOP 
	while (!glfwWindowShouldClose(m_mainWindow)) {
		// Get and handle User Input Event
		glfwPollEvents();

		// Clear Window
		glClearColor(.2f, .2f, .2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_mainWindow);
	}

}