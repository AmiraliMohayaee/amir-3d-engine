#include "Cloth.h"
#include <cmath>

namespace Engine
{
	Cloth::Cloth()
	{
		m_row = 0;
		m_column = 0;
	}

	Cloth::~Cloth()
	{
		
	}

	// Devised collision check function with a sphere
	// Not implemented yet
	//void Cloth::CollisionCheck(const CollisionSphere &sphere)
	//{
	//	Vec3f spherePos = sphere.GetPos();
	//	float sphereRad = std::powf(sphere.GetRadius(), 2);

	//	for (unsigned int i = 0; i < m_particles.size(); i++)
	//	{
	//		for (unsigned int j = 0; j < m_particles[i].size(); j++)
	//		{
	//			Vec3f diff = m_particles[i][j].GetPos() - spherePos;

	//			if (diff.SqrLength() < sphereRad)
	//			{
	//				// Sphere and particles are colliding and we do a collision response
	//				diff.Normalize();
	//				diff * sphere.GetRadius();
	//				Vec3f newPartPos = spherePos + diff;
	//				m_particles[i][j] = newPartPos;
	//			}
	//		}
	//	}
	//}

	void Cloth::Initialize(float kValue, float minValue, float maxValue, float naturalLength, 
			unsigned int rows, unsigned int columns, float particleInvMass)
	{
		// These will be called regardless before making a lattice
		//SetRows(row);
		//SetColumns(columns);
		
		m_row = rows;
		m_column = columns;


		Spring newSpring;
		newSpring.SetKVal(kValue);
		newSpring.SetMinAndMaxVal(minValue, maxValue);
		newSpring.SetNaturalLength(naturalLength);


		// Setting up thye multidimentional vector of particles
		m_particles = ColumnVec(columns, RowVec(rows, Particle()));

		// The rows in the RowVec are aligned on the x-axis and the 
		// columns in the ColumnVec on the y-axis

		// Making a lattice 
		for (unsigned int r = 0; r < rows; r++)
		{
			for (unsigned int c = 0; c < columns; c++)
			{
				// Setting every new particle's position and mass
				m_particles[r][c].SetPos(Vec3f((float)r * naturalLength, 
					(-static_cast<float>(static_cast<int>(c)) * naturalLength), 
					0));
				m_particles[r][c].SetInvMass(particleInvMass);

				// Setting the top row of particles as static to give
				// the impression of a natural hanging cloth
				if (c == 0)
				{
					m_particles[r][c].SetInvMass(0);
				}

				//  Setting up the horizontal springs
				if (r < rows-1)
				{
					newSpring.SetParticles(&(m_particles[r][c]), &(m_particles[r + 1][c]));
					m_springs.push_back(newSpring);
				}

				//// Vertical springs
				if (c < columns-1)
				{
					newSpring.SetParticles(&(m_particles[r][c]), &(m_particles[r][c + 1]));
					m_springs.push_back(newSpring);
				}

				//// Digonal Springs set up in -x +y direction
				if ((c > 0 && r < rows-1))
				{
					newSpring.SetParticles(&(m_particles[r][c]), &(m_particles[r + 1][c - 1]));
					m_springs.push_back(newSpring);
				}

				////// Diagonal Springs set up in +x +y direction
				if (c > 0 && r > 0)
				{
					newSpring.SetParticles(&(m_particles[r][c]), &(m_particles[r - 1][c - 1]));
					m_springs.push_back(newSpring);
				}
			}
		}
	}
	

	void Cloth::DrawLattice()
	{
		for (ColumnVec::iterator  it = m_particles.begin();
			it != m_particles.end();
			it++)
		{
			RowVec& rv = *it; 
			for (unsigned int i = 0; i < rv.size(); i++)
			{
				rv[i].DrawGL();
			}
		}

		for (Springs::iterator  it = m_springs.begin();
			it != m_springs.end();
			it++)
		{
			(it)->Draw();
		}
	}

	void Cloth::DrawTriangles()
	{

	}

	void Cloth::Update()
	{		
		//GetClothVals();

		for (ColumnVec::iterator  it = m_particles.begin();
			it != m_particles.end();
			it++)
		{
			RowVec& rv = *it; 
			for (unsigned int i = 0; i < rv.size(); i++)
			{
				rv[i].Update();
			}
		}

		for (Springs::iterator  it = m_springs.begin();
			it != m_springs.end();
			it++)
		{
			(it)->Update();
			//GetClothVals();
		}
	}
}





	// Below is an alternate method of setting up the lattice, however it is
	// more complicated. It has the benefit of speed compared to the brute force
	// method of above 
	/*
	// From here, we set up all springs in order
	// Corners
	// Top Left corner element
	if(r == 0 && c == 0)
	{
		newSpring.SetParticles(&m_particles[0][0], &m_particles[1][0]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][0], &m_particles[1][1]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][0], &m_particles[0][1]);
		m_springs.push_back(newSpring);
	}

	// Top Right corner Element
	else if (r == rows && c == 0)
	{
		newSpring.SetParticles(&m_particles[rows][0], &m_particles[rows][c+1]);
		m_springs.push_back(newSpring);
	}

	//Bottom Left corner element
	else if (r == 0 && c == columns)
	{
		newSpring.SetParticles(&m_particles[0][columns], &m_particles[1][columns]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][columns], &m_particles[1][columns-1]);
		m_springs.push_back(newSpring);
	}

	// Bottom Right corner element
	else if (r == rows && c == columns)
	{
		//nothing if we've done the other elements
		return;
	}

	// Edges
	// Top Edge element
	if (r == 0 && c == (rows*columns)/2)
	{
		newSpring.SetParticles(&m_particles[0][0], &m_particles[0][columns+1]);
		m_springs.push_back(newSpring);
	}
				
	// Left Edge Element
	else if (r == 0 && c >= 1)
	{
		newSpring.SetParticles(&m_particles[0][1], &m_particles[1][0]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][1], &m_particles[1][1]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][1], &m_particles[1][2]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][1], &m_particles[0][2]);
		m_springs.push_back(newSpring);
	}
				
	// Right Edge
	else if (r == rows && c == columns)
	{
		newSpring.SetParticles(&m_particles[r-1][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);
	}
				
	// Bottom Left Corner
	else if (r == 0 && c == columns)
	{
		newSpring.SetParticles(&m_particles[0][c], &m_particles[r+1][c]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[0][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);
	}
				
	// Centre
	else if (!r == 0 && c == (columns * 0.5f))
	{
		newSpring.SetParticles(&m_particles[r/2][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[r-1][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[r-1][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);

		newSpring.SetParticles(&m_particles[r-1][c], &m_particles[r][c]);
		m_springs.push_back(newSpring);
	}
	*/