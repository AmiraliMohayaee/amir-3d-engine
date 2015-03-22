#ifndef SPRING_H_INCLUDED
#define SPRING_H_INCLUDED

#include "Vec3.h"


namespace Engine
{
	// Particles acts as a friend
	class Particle;

	class Spring
	{
	public:
		Spring();
		~Spring();

		void Draw();
		void Update();

		void SetParticles(Particle* p1, Particle* p2);
		
		void SetDamping();

		void SetKVal(float k);
		void SetMinAndMaxVal(float min, float max);
		void SetNaturalLength(float naturalLength);

		float GetKVal() const;
		float GetMinVal() const;
		float GetMaxVal() const;
		float GetNaturalLength() const;

		// Checking if particles are movable or not
		// This is used when wanting to check to see
		// if the length of a psring has to be decreased or not
		bool CheckMovable();

		void SetMovable();
		void SetImmovable();

	private:
		float m_kValue;
		float m_naturalLength;
		float m_minLength;
		float m_maxLength;
		Particle* m_particles[2];


		Vec3f m_diff;	// Vector between two particles
		float m_diffLen;	// Length between two particles
		Vec3f m_centrePoint;	// Centre point between two particles

		// Length vectors either pointing towards or away
		Vec3f m_newLengthPositive;
		Vec3f m_newLengthNegative;
		Vec3f m_force;	// Stores the force being applied to a particle
	};
}

#endif