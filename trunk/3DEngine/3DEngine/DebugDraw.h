#pragma once

#include "Vec3.h"
#include "MyGL.h"


namespace Engine
{
	class DebugDraw
	{
	private:
		Vec3f x, y, z;

	public:
		//DebugDraw();
		//DebugDraw() : 

		//void DrawNormal(Vec3f a, Vec3f b)
		//{
		//	Vec3f c;
		//	//c.CrossProduct(a, b);

		//	Vec3f d;
		//	d = b - a;
		//	Vec3f e;
		//	e = c - a;

		//	glPushMatrix();
		//	glColor3f(1.0, 0.0, 0.0);
		//	glBegin(GL_LINES);
		//	//glVertex3f(v.x, v.y, v.z);
		//	glVertex3f(15, 0, 0);
		//	glPopMatrix();
		//}

		void DrawXLine()
		{
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_LINES);
			//glVertex3f(v.x, v.y, v.z);
			glVertex3f(0, 0, 0);
			glVertex3f(2.0, 0, 0);
			glEnd();
			glPopMatrix();
		}

		void DrawYLine()
		{
			glPushMatrix();
			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_LINES);
			//glVertex3f(v.x, v.y, v.z);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 2.0, 0);
			glEnd();
			glPopMatrix();
		}

		void DrawZLine()
		{
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glBegin(GL_LINES);
			//glVertex3f(v.x, v.y, v.z);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 2.0);
			glEnd();
			glPopMatrix();
		}

		// Draws all three coords 
		void DrawCoordID()
		{
			DrawXLine();
			DrawYLine();
			DrawZLine();
		}
	};
}