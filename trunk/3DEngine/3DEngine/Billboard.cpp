#include "Billboard.h"
#include "MyGL.h"


namespace Engine
{
	Billboard::Billboard()
	{

	}

	void Billboard::Draw(const Vec3f& pos, float s) // s representing sides
	{
		// f is the array of 16 floats,
		// taking in the matrix elements

		float f[16];

		glGetFloatv(GL_MODELVIEW_MATRIX, f); 

		Vec3f right(f[0], f[4], f[8]);
		Vec3f up(f[1], f[5], f[9]);
		up *= s;
		right *= s;

		Vec3f topLeft = pos + up - right;
		Vec3f topRight = pos + up + right;
		Vec3f bottomLeft = pos - up - right;
		Vec3f bottomRight = pos - up + right;


		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(topLeft.x, topLeft.y, topLeft.z);

		glTexCoord2f(0, 1);
		glVertex3f(bottomLeft.x, bottomLeft.y, bottomLeft.z);

		glTexCoord2f(1, 1);
		glVertex3f(bottomRight.x, bottomRight.y, bottomRight.z);

		glTexCoord2f(1, 0);
		glVertex3f(topRight.x, topRight.y, topRight.z);

		// ^^^going through the vertecies in anti-clockwise
		// motion so that the billboard is front-facing
		glEnd();
	}
}