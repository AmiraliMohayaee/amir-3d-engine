#include "Light.h"
#include "MyGL.h"
#include <math.h>


namespace Engine
{
	void Light::SetLightDirection(float lightposX, float lightposY, 
		float lightposZ)
	{
		m_lightposX = lightposX;
		m_lightposY = lightposY;
		m_lightposZ = lightposZ;

		GLfloat light_direction[4] = 
		{ lightposX, lightposY, lightposZ, 0.0 };

		glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
	}


	void Light::SetLightPos(float lightposX, float lightposY, 
		float lightposZ)
	{
		m_lightposX = lightposX;
		m_lightposY = lightposY;
		m_lightposZ = lightposZ;

		GLfloat light_direction[4] = 
		{ lightposX, lightposY, lightposZ, 1.0 };

		glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
	}


	void Light::SetAmbient(
		float r, 
		float g, 
		float b, 
		float a)
	{
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);

		GLfloat ambientL[4] = { r, g, b, a };

		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientL);
	}


	void Light::SetDiffuse(
		float r,
		float g,
		float b,
		float a)
	{
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);

		GLfloat diffuseL[4] = { r, g, b, a };

		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseL);
	}


	void Light::SetSpecular(
		float r,
		float g,
		float b,
		float a)
	{
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);

		GLfloat specularL[4] = { r, g, b, a };

		glLightfv(GL_LIGHT0, GL_SPECULAR, specularL);
	}
}