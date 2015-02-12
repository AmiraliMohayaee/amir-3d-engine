#ifndef CAPSULE_H
#define CAPSULE_H

#include "LineSeg3.h"

namespace Engine
{
	class Capsule
	{
	public:
		Capsule() {}
		Capsule(const LineSeg3& lineSeg, float radius) : m_lineSeg(lineSeg), m_radius(radius) {}

		const LineSeg3& GetLineSeg() const { return m_lineSeg; }
		float GetRadius() const { return m_radius; }

	private:
		LineSeg3 m_lineSeg;
		float m_radius;
	};
}

#endif