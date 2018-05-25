#include "DisplayWindow.h"
#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Mesh.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	


	DisplayWindow displayWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL");												 
	// --------------------
	std::string shaderFilePath = "res\\basicShader";
	Shader shader(shaderFilePath);


	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5,-0.5,0)),
		Vertex(glm::vec3(0,0.5,0)),
		Vertex(glm::vec3(0.5,-0.5,0))
	};
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));


	// render loop
	// -----------
	while (!displayWindow.isClosed())
	{
		// render
		// ------
		displayWindow.Clear(0.2,0.3,0,1);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		shader.Bind();
		mesh.Draw();

		displayWindow.Update();
		Sleep(10);
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	
	return 0;
}


