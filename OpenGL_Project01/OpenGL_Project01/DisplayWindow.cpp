#include "DisplayWindow.h"




DisplayWindow::DisplayWindow(int width, int height, const std::string & nameWindow)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width,height, nameWindow.c_str(), NULL, NULL);


}

DisplayWindow::~DisplayWindow()
{
	glfwTerminate();
}
