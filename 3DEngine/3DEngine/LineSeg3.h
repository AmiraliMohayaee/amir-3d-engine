#ifndef LINE_SEG_3_H_INCLUDED
#define LINE_SEG_3_H_INCLUDED

#include "Vec3.h"


namespace Engine
{
	struct LineSeg3
	{
		LineSeg3() {}
		LineSeg3(Vec3f point0, Vec3f point1) : p0(point0), p1(point1) {}

		float Range(Vec3f q)
		{
			Vec3f m = p1 - p0;

			float t = DotProduct(m, q - p0) / DotProduct(m, m);

			if (t < 0)
			{
				return (q - p0).SqrLength();
			}

			if (t > 1)
			{
				return (q - p1).SqrLength();
			}
			else
			{
				Vec3f p = p0 + m * t;

				return (q - p).SqrLength();
			}
		}

		const Vec3f& GetStart() const { return p0; }
		const Vec3f& GetEnd() const { return p1; }

		Vec3f p0;
		Vec3f p1;
	};
}

#endif