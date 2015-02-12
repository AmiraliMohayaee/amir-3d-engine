#pragma once

#include <Windows.h>
#include "MyGL.h"
#include "Colour.h"


// Colour set for setting colours to an object
namespace Engine
{
	struct Colour
	{
		Colour(float pr = 1.0f, float pg = 1.0f, float pb = 1.0f, float pa = 1.0f) : 
			r(pr), g(pg), b(pb), a(pa)
			{
			}

		void Draw()
		{
			glColor4f(r, g, b, a);
		}
		
		void SetColours(float red, float green, float blue, float alpha)
		{
			glColor4f(red, green, blue, alpha);
		}

		float GetColours()
		{
			return r, g, b, a;
		}


		float r, g, b, a;
	};
}