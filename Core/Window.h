#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

#pragma once

class Window
{
public:
	Window(GLint width, GLint height);
	void Init();
	void Loop();

private:
	GLint m_width;
	GLint m_height;
	GLFWwindow* m_mainWindow;
};



