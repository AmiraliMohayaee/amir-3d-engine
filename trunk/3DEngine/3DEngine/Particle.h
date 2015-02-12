#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "Vec3.h"
#include "Spring.h"

// Some code snippets were taken from Jesper Mosegaard and his cloth physics demo: 
// http://cg.alexandra.dk/2009/06/02/mosegaards-cloth-simulation-coding-tutorial/
// While the example is not following the exact example 

namespace Engine
{
	class Particle
	{
	public:
		enum ROWS { NUMROWS, NUMCOLUMS };

		Particle();
		Particle(Vec3f pos) : m_pos(pos), m_oldPos(pos), m_bMovable(true) {} 
		Particle(float invmass) : m_invMass(invmass) {}


		bool Movable(); // Boolean for checking if object is movable or not

		void DrawGL();
		void DrawDX();

		void Update();
		void UpdateEuler();
		void UpdateVerlet();

		void AddForce(Vec3f f);
		void TimeStep();
		Vec3f& GetPos();
		void SetInvMass(float invMass);
		void SetPos(const Vec3f& pos);
		void ResetAcc();
		void PosOffset(const Vec3f& offset);
		void MakeUnmovable();
		
		// Not used at the moment
		const void AddToNormal(Vec3f& normal);
		Vec3f& GetNormal(); // vector normal not unit length
		void ResetNormal();

	private:
		Vec3f m_oldVel;
		Vec3f m_vel;
		Vec3f m_acceleration;
		float m_mass;
		float m_invMass;

		Vec3f m_forces;
		Vec3f m_oldPos;
		Vec3f m_pos;

		// These variables were suggested by Jesper Mosegaard
		Vec3f m_accumulatedNormal; // Accumulated normal used for OpenGL soft shading
		bool m_bMovable; // Checking if a particle is movable or not
	};
}


#endif