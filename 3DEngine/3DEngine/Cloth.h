#ifndef CLOTH_H_INCLUDED
#define CLOTH_H_INCLUDED

#include <math.h>
#include <vector>
#include <iostream>
#include "Vec3.h"
#include "Particle.h"
#include "Constraint.h"
#include "Spring.h"
#include "MyGL.h"
#include "CollisionSphere.h"


namespace Engine
{
	class Particle;
	class Spring;
	
	class Cloth
	{
	public:
		Cloth();
		
		~Cloth();

		// Sets and calculates all values 
		void Initialize(float kValue, unsigned int row, 
			unsigned int column, float particleInvMass);

		void DrawLattice();
		void DrawTriangles();	// Todo later
		void Update();


		float GetClothMass();
		float GetMassPerFace();
		float GetColumnStep();
		float GetRowStep();
		float GetClothVals();


		//void CollisionCheck(const CollisionSphere &sphere);


	private:
		// The Row vector
		typedef std::vector<Particle> RowVec;
		// Multidimentional column array representing both
		typedef std::vector<RowVec> ColumnVec;
		

		typedef std::vector<Spring> Springs;


		ColumnVec m_particles;
		Springs m_springs;

		float m_constraint;

		unsigned int m_row;
		unsigned int m_column;
	};


	//inline
	//	const void GetClothVals(float kValue, float minValue, float maxValue, float naturalLength)
	//{


	//{

}

#endif