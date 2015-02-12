#ifndef MATERIAL_H
#define MATERIAL_H

#include "MyGL.h"
#include "GameObject.h"
#include "Light.h"

namespace Engine
{
	class Material /*: public GameObject*/
	{
	public:
		Material();

		void ApplyAmbient(float r,
			float g,
			float b,
			float a);

		void ApplyDiffuse(float r,
			float g,
			float b,
			float a);

		void ApplySpecular(float r,
			float g,
			float b,
			float a);

		void ApplyShininess(float shine);

	private:
		GLfloat ambientM[4];
		GLfloat diffuseM[4];
		GLfloat specularM[4];

		GLfloat shininess;
	};
}

#endif