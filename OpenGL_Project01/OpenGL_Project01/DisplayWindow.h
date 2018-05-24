#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class DisplayWindow
{
public:
	DisplayWindow(int width,int height, const std::string & nameWindow);
	~DisplayWindow();

	GLFWwindow* GetWindowPtr() { return window; }
private:
	GLFWwindow* window;
};

