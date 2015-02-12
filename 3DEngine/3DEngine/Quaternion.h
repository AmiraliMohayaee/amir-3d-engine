// Maths for Game Programming
// Quaternion class - to be completed in lesson
// Jason Colman Qantm London 2009

#ifndef QUATERNION_H_INCLUDED
#define QUATERNION_H_INCLUDED

#include "Vec3.h"
#include <assert.h>
#include <math.h>


namespace Engine
{
	class Quaternion
	{
	public:
		// Default ctor - set to identity
		Quaternion() : m_w(1.0f), m_x(0), m_y(0), m_z(0) {}

		// Ctor - set from axis and angle
		Quaternion(float angleDegrees, const Vec3f axis)
		{
			float radiansOver2 = DegToRad(angleDegrees) * 0.5f;
			m_w = cos(radiansOver2);
			float s = sin(radiansOver2);
			m_x = axis.x * s;
			m_y = axis.y * s;
			m_z = axis.z * s;
		}


		float SqrLength() const
		{
			return m_w * m_w + m_x * m_x + m_y * m_y + m_z * m_z;
		}

		int Length() const
		{		
			return static_cast <float>(sqrt(SqrLength()));
		}

		void Normalize();

		// Convert to column-major Matrix
		void ToMatrix(float matrix[16]) const;

		// Interpolate between two Quaternions
		// 0 <= t <= 1
		friend Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t);

		friend Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

		Vec3f RotateVec(const Vec3f& v);

		Quaternion Conjugate();

	private:
		float m_w;
		float m_x;
		float m_y;
		float m_z;
	};
}

#endif 