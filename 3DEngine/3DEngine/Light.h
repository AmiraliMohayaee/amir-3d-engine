#ifndef LIGHT_H
#define LIGHT_H

#include "MyGL.h"
#include "GameObject.h"
#include "Vec3.h"

namespace Engine
{
	class Light /*: public GameObject*/
	{
	public:
		Light(): m_lightposX(0), m_lightposY(0), m_lightposZ(0) {}
		//Light(Vec3f x, Vec3f y, Vec3f z): m_lightposX(x), m_lightposY(y), m_lightposZ(z) {}

		void Load();
		void Draw();

		void SetShininess();

		// Directional Light
		void SetLightDirection(float m_lightposX, float m_lightposY,
			float m_lightposZ);

		// Positional Light
		void SetLightPos(float m_lightposX, float m_lightposY,
			float m_lightposZ);

		void SetAmbient(float r,
			float g,
			float b,
			float a);

		void SetDiffuse(float r,
			float g,
			float b,
			float a);

		void SetSpecular(float r,
			float g,
			float b,
			float a);

	private:
		GLfloat ambientL[4];
		GLfloat diffuseL[4];
		GLfloat specularL[4];

		GLfloat light_direction[4];

		float m_lightposX;
		float m_lightposY;
		float m_lightposZ;
	};
}

#endif