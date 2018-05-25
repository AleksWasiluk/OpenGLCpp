#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class DisplayWindow
{
public:
	DisplayWindow(int width,int height, const std::string & nameWindow);
	~DisplayWindow();
	void Update();
	GLFWwindow* GetWindowPtr() { return window; }
	bool isClosed();
	void Clear(GLfloat, GLfloat, GLfloat, GLfloat);
private:
	GLFWwindow* window;
	void processInput(GLFWwindow *window);
};

