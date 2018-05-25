#pragma once

#include <glm\glm.hpp>
#include <glad\glad.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:
private:
	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices,const unsigned int numVertices);
	void Draw();
	~Mesh();
private:
	GLuint vertexArrayObject;
	enum{POSITION_VB,NUM_BUFFERS};
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned int drawCount;
};

