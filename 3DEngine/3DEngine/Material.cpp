#include "Material.h"
#include <memory.h>
#include "MyGL.h"

Engine::Material::Material()
{
	// Setting all values to Null
	memset (ambientM, 0, sizeof(GLfloat) * 4);
	memset (diffuseM, 0, sizeof(GLfloat) * 4);
	memset (specularM, 0, sizeof(GLfloat) * 4);

	//ambientM[0] = NULL;
	//ambientM[1] = NULL;
	//ambientM[2] = NULL;
	//ambientM[3] = NULL;

	//diffuseM[0] = NULL;
	//diffuseM[1] = NULL;
	//diffuseM[2] = NULL;
	//diffuseM[3] = NULL;

	//specularM[0] = NULL;
	//specularM[1] = NULL;
	//specularM[2] = NULL;
	//specularM[3] = NULL;
}

void Engine::Material::ApplyAmbient(float r,
	float g,
	float b,
	float a)
{

	glDisable(GL_COLOR_MATERIAL);

	GLfloat ambientM[4] = { r, g, b, a };

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientM);
}

void Engine::Material::ApplyDiffuse(float r,
	float g,
	float b,
	float a)
{

	glDisable(GL_COLOR_MATERIAL);

	GLfloat diffuseM[4] = { r, g, b, a };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseM);
}

void Engine::Material::ApplySpecular(float r,
	float g,
	float b,
	float a)
{
	glDisable(GL_COLOR_MATERIAL);

	GLfloat specularM[4] = { r, g, b, a };

	glMaterialfv(GL_FRONT, GL_SPECULAR, specularM);
}

void Engine::Material::ApplyShininess(float shininess)
{
	glDisable(GL_COLOR_MATERIAL);

	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}