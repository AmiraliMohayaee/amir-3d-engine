#pragma once

#include <iostream>
#include "Matrix.h"
#include "EventHandler.h"
#include "Vec4.h"


namespace Engine
{
	int mouseX, mouseY;
	int width, height;

	void OnMouseButtonEvent(const SDL_MouseButtonEvent& b)
	{
		if (b.state == SDL_MOUSEBUTTONDOWN  && b.button == SDL_BUTTON_LEFT)
		{
			std::cout << "Left Mouse button in pressed";
		}
	}

	void OnMouseMotionEvent(const SDL_MouseButtonEvent& m)
	{
		if (m.type == SDL_MOUSEMOTION)
		{
			
		}
	}

	void Pick()
	{
		// Create line seg. The start point is the mouse coord,
		//  converted to 3D world coords, with depth 0.
		// The other end has depth 1.
	
		// Do it all by ourselves
		// ----------------------

		// Get inverse clip matrix
		//Matrix modl;
		//modl.ModelView();
		//Matrix proj;
		//proj.Projection();
		//Matrix clip = modl * proj;
		//Matrix inv;
		//clip.Inverse(&inv);

		//// Convert mouse (x, y) into world coords at zero depth
		//float x = 2.0f * ((float)mouseX / (float)width) - 1.0f; // between -1 and 1
		//float y = 2.0f * (1.0f - (float)mouseY / (float)height) - 1.0f;

		//// Convert x, y, z from clip space to world space
		//// We must divide by w -- so need the homogenous coord,
		////  not just the Vec3.
		//Vec4f q1 = Vec4f(x, y, -1.0, 1.0) * inv; // near
		//Vec4f q2 = Vec4f(x, y, 1.0,  1.0) * inv; // far

		//Vec3f lineSegStart (q1.x / q1.w, q1.y / q1.w, q1.z / q1.w);
		//Vec3f lineSegEnd (q2.x / q2.w, q2.y / q2.w, q2.z / q2.w);
	

		// Using gluUnProject
		// ------------------
		//int viewport[4];
		//glGetIntegerv(GL_VIEWPORT,viewport);
		//double modl[16], proj[16];
		//glGetDoublev(GL_MODELVIEW_MATRIX, modl);
		//glGetDoublev(GL_PROJECTION_MATRIX, proj);
		//double x, y, z;

		//gluUnProject(mouseX, height - mouseY, 0, modl, proj, viewport, &x, &y, &z);
		//Vec3f lineSegStart = Vec3f(x, y, z);

		//gluUnProject(mouseX, height - mouseY, 1, modl, proj, viewport, &x, &y, &z);
		//Vec3f lineSegEnd = Vec3f(x, y, z);
	}
}