#ifndef VEC_2_H
#define VEC_2_H


namespace Engine
{
	template <class T>
	class Vec2
	{
	public:

		T x, y;
		/*int x;
		int y;*/

		//cntr
		Vec2() : x(0), y(0) { } //Initializing members for constructor

		//another cntr with memebrs initialized
		Vec2(T px, T py) : x(px), y(py) { }; //p for parameter


		Vec2& operator+=(const Vec2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		//Member version
		Vec2 operator+(const Vec2& rhs) const
		{
			Vec2 result = *this;
			result += rhs;
			return result;
		}

		Vec2& operator*=(float f)
		{
			x *= f;
			y *= f;
			return *this;
		}

		Vec2 operator*(float f)
		{
			Vec2 result = *this;
			result *= f;
			return result;
		}
	};

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;

	//Non-member version
	//template <class T>
	//Vec2<T> operator+(const Vec2&<T> a, const Vec2&<T> b)
	//{
	//	Vec2<T> result = a;
	//	result += b;
	//	return result;
	//}
}

#endif