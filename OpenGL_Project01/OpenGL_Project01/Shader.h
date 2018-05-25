#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <glad\glad.h>


class Shader
{
public:
	Shader(std::string &fileName);
	void Bind();
	~Shader();
	static GLuint CreateShader(const std::string& textprogram, GLenum shaderType);
private:
	static enum shaders{VertexShader,FragmentShader};
	static const unsigned int NUMBER_SHADERS = 2;
	GLuint program;
	GLuint shader[NUMBER_SHADERS];
};

