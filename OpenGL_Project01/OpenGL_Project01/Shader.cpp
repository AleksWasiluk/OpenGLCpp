#include "Shader.h"
static std::string LoadShaderFromFile(const std::string & fileName);
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

Shader::Shader(std::string & fileNamePath)
{
	program = glCreateProgram();
	shader[Shader::VertexShader] = CreateShader(LoadShaderFromFile(fileNamePath + ".vs"), GL_VERTEX_SHADER);
	shader[Shader::FragmentShader] = CreateShader(LoadShaderFromFile(fileNamePath + ".fs"), GL_FRAGMENT_SHADER);

	//atach shaders
	for (unsigned int i = 0; i < NUMBER_SHADERS; i++)
		glAttachShader(program, shader[i]);

	glBindAttribLocation(program, 0, "position");
	
	glLinkProgram(program);
	//Check for Errors
	CheckShaderError(program, GL_LINK_STATUS, true, "Error Shader Program failed to link");

	glValidateProgram(program);
	//Check for Errors
	CheckShaderError(program, GL_VALIDATE_STATUS, true, "Error Shader Program is invalid");

}

void Shader::Bind()
{
	glUseProgram(program);
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUMBER_SHADERS; i++)
	{
		glDetachShader(program, shader[i]);
		glDeleteShader(shader[i]);
	}
	glDeleteProgram(program);
}

GLuint Shader::CreateShader(const std::string & textProgram, GLenum shaderType)
{
	auto shader = glCreateShader(shaderType);
	if (shader == 0)
		std::cerr << "Error : shader creation failed!" << std::endl;

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];
	
	shaderSourceStrings[0] = textProgram.c_str();
	shaderSourceStringLengths[0] = textProgram.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "ERROR : compilation shader failed");

	return shader;
}

std::string LoadShaderFromFile(const std::string & fileName)
{
	
	std::ifstream file("");
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	file.open(fileName.c_str(), std::ifstream::app);
	std::string output;
	std::string line;

	if (file.is_open())
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	else
		std::cerr << "Unable to load shader: " << fileName << std::endl;

	return output;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}

}