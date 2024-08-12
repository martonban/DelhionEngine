#include<stdio.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include "Window.h";

// Window sizes
const GLint WIDTH = 800, HEIGHT = 600;


int main() {

	Window& window = Window::GetInstance();

	window.Init(1300, 800);
	
	try {
		window.Start();
	}
	catch (const std::exception& e) {
		std::cout << "ERROR: " << e.what();
		return 1;
	}
	
	window.Loop();

	return 0;
}