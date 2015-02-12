#pragma once

#include "Vec3.h"
#include "Particle.h"

namespace Engine
{
	class Particle;

	class Constraint
	{
	public:
		Particle *p1, *p2; // the two particles that are connected through this constraint

		// Get the vector length between the two particles 
		Constraint(Particle *p1, Particle *p2) :  p1(p1), p2(p2)
		{
			Vec3f dist = p1->GetPos() - p2->GetPos();
			m_restDistance = dist.Length();
		}

		/* This is one of the important methods, where a single constraint between two particles p1 and p2 is solved
		the method is called by Cloth.time_step() many times per frame*/
		void satisfyConstraint()
		{
			Vec3f p1_to_p2 = p2->GetPos()-p1->GetPos(); // vector from p1 to p2
			float current_distance = p1_to_p2.Length(); // current distance between p1 and p2
			
			// The offset vector that could moves p1 into a distance of rest_distance to p2
			Vec3f correctionVector = p1_to_p2*(1 - m_restDistance/current_distance);

			// Lets make it half that length, so that we can move BOTH p1 and p2.
			Vec3f correctionVectorHalf = correctionVector*0.5; 			
			
			// correctionVectorHalf is pointing from p1 to p2, 
			// so the length should move p1 half the length needed to satisfy the constraint.
			p1->PosOffset(correctionVectorHalf); 

			// we must move p2 the negative direction 	
			// of correctionVectorHalf since it points from p2 to p1, and not p1 to p2
			p2->PosOffset(-correctionVectorHalf); 		
		}

	private:
		float m_restDistance; // the length between particle p1 and p2 in rest configuration
	};
}