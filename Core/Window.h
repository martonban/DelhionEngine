#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

#pragma once

class Window
{
public:
	void Init(GLint width, GLint height);
	void Start();
	void Loop();


	static Window& GetInstance() {
		static Window instance;
		return instance;
	}

protected:
	Window() = default;

private:
	GLint m_width;
	GLint m_height;
	GLFWwindow* m_mainWindow;
};



