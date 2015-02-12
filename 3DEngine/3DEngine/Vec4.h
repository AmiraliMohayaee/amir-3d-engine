#pragma once
//--------------------------------------------------------------------------------------
// File: Vector3.h
//
// This is the Vector2 structure (Add description of what it does)
//
// Copyright (c) Precious Roy. All rights reserved. ;)
// Date: 29-1-2014
//--------------------------------------------------------------------------------------
#include <math.h>


namespace Engine
{
	template <class T>
	class Vec4
	{
	public:
		T x;
		T y;
		T z;
		T w;

		Vec4(): x(0), y(0), z(0), w(0) {}
		Vec4(T px, T py, T pz, T pw) : x(px), y(py), z(pz), w(pw) {}


		Vec4 operator+(const Vec4& rhs) const
		{
			Vec4 result = *this;
			result += rhs;
			return result;
		}

		Vec4& operator-=(const Vec4& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		Vec4 operator-(const Vec4& rhs) const
		{
			Vec4 result = *this;
			result -= rhs;
			return result;
		}

		Vec4 operator-() const
		{
			Vec4 result(-x, -y, -z, -w);
			return result;
		}

		Vec4& operator*=(T f)
		{
			x *= f;
			y *= f;
			z *= f;
			w *= f;
			return *this;
		}

		Vec4 operator*(T f) const
		{
			return Vec4(x * f, y * f, z * f, w * f);
			//Vec4 result = *this;
			//result *= f;
			//return result;
		}

		Vec4& operator/=(T t) const
		{
			x /= t;
			y /= t;
			z /= t;
			w /= t;
			return *this;
		}

		Vec4 operator/ (T f) const
		{
			return Vec4(x/f, y/f, z/f, w/f);
		}

		float Length() const
		{
			return sqrt(SqrLength());
		}

		float SqrLength() const
		{
			return (x * x + y * y + z * z) / w;
		}

		void Normalize()
		{
			T oneOverLen = 1.0f / Length();
			*this *= oneOverLen;
			assert(SqrLength() > 0.99f && SqrLength() < 1.01f);
		}

		Vec4<T> CrossProduct(const Vec4<T>& u, const Vec4<T>& v)
		{
			return Vec4<T>((u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v. z,
				u.x * v.y - u.y * v.x) / w);
		}

		T DotProduct(const Vec4<T>& u, const Vec4<T>& v)
		{
			return ((u.x * v.x + u.y * v.y + u.z * v.z) / w);
		}
	};

	typedef Vec4<int> Vec4i;
	typedef Vec4<float> Vec4f;
}