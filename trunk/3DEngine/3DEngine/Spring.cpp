#include "Spring.h"
#include <stdlib.h>
#include <assert.h>
#include "Vec3.h"
#include "Particle.h"
#include "MyGL.h"

namespace Engine
{
	Spring::Spring()
	{
		m_particles[0] = NULL;
		m_particles[1] = NULL;
	}

	Spring::~Spring()
	{

	}

	void Spring::Draw()
	{
		Vec3f p1 = m_particles[0]->GetPos();
		Vec3f p2 = m_particles[1]->GetPos();

		glLineWidth(3);
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glEnd();
	}

	void Spring::SetParticles(Particle* p1, Particle* p2)
	{
		m_particles[0] = p1;
		m_particles[1] = p2;
	}

	void Spring::Update()
	{
		// Checking for particles
		assert(m_particles[0]);
		assert(m_particles[1]);

		// Get vector between points
		Vec3f diff = 
			m_particles[1]->GetPos() -
			m_particles[0]->GetPos();

		// Get difference between dist and natural length = x
		// (clamp x ?)
		float diffLen = diff.Length();
		float x = diffLen - m_naturalLength;
		//if (fabs(diffLen) < 0.0001f)	// fabs function returns absolute value of a float
		//{
		//	return;
		//}
		if ((x < 0.01f) && (x > -0.01f))
		{
			return; 
		}

		// Hooke's Law; F = -k x
		diff.Normalize();	// Normalizing the vector before doing elasticity check
		Vec3f force = diff * (-m_kValue * x);

		// Vector centrepoint
		//Vec3f CentrPoint = ((m_particles[0]->GetPos() - m_particles[1]->GetPos()) * 0.5f); 
		Vec3f centrePoint = (diff * (diffLen * 0.5));

		// New length vectors pointing towards and away
		Vec3f newLengthPositive = diff * (m_maxLength * 0.5);
		Vec3f newLengthNegative = diff * -(m_maxLength * 0.5);
		
		
		// Damping
		// enforcing min and maxlengths and clamping
		if (diffLen > m_maxLength)
		{
			//float extra = diffLen - m_maxLength;
			//Vec3f newLength = diff * (extra/2);

			
			// checking if particle is immovable or not
			// decreasing the length if it goes above maxlength and if movable
			// if (particle  is movable)
			// diff = (maxlength - (particle0 - particle 1)
			// same as above for minlength, except in negative distance


			// Both movable
			if (m_particles[0]->Movable() && m_particles[1]->Movable())
			{
				std::cout << "Checking maxlength. Both objects are movable, offsetting position of "<<
					 "both particles.\n";

				m_particles[0]->SetPos(centrePoint - (newLengthNegative));
				m_particles[1]->SetPos(centrePoint + (newLengthPositive));

				// Pos Offsetting for some testing
				//m_particles[0]->PosOffset(-newLength);
				//m_particles[1]->PosOffset(newLength);
			}
			// If both immovable
			else if (!m_particles[0]->Movable() && !m_particles[1]->Movable())
			{
				// Both immovable, Do nothing
				std::cout << "Checking Maxlength. Both particles are immovable.\n";
			}
			// First one is movable but the other is not
			else if (m_particles[0]->Movable() && !m_particles[1]->Movable())
			{
				std::cout << "Checking Maxlength. Only the first prticle is movable.\n";
				m_particles[0]->SetPos(m_particles[1]->GetPos() - (diff * m_maxLength));
			}
			else
			{
				//m_particles[1]->PosOffset(diff * extra);
				std::cout << "Checking Maxlength. Only the second prticle is movable.\n";
				m_particles[1]->SetPos(m_particles[0]->GetPos() - (-diff * m_maxLength));
			}
		}
		else if (diffLen < m_minLength)
		{
			float extra = diffLen - m_maxLength;
			Vec3f newLength = diff * (extra/2);

			// Both movable
			if (m_particles[0]->Movable() && m_particles[1]->Movable())
			{
				std::cout << "Checking minlength. Both particles are movable.";
				// Damping
				//Vec3f CentrPoint = ((m_particles[0]->GetPos() - m_particles[1]->GetPos()) * 0.5f); 

				m_particles[0]->SetPos(centrePoint - (diff * (m_minLength * 0.5f)));
				m_particles[1]->SetPos(centrePoint + (diff * (m_minLength * 0.5f)));

				
				// Pos Offsetting for some testing
				//m_particles[0]->PosOffset(-newLength);
				//m_particles[1]->PosOffset(newLength);
			}

			// If both immovable
			else if (!m_particles[0]->Movable() && !m_particles[1]->Movable())
			{
				// Both immovable, Do nothing
				std::cout << "Checking minlength. Both particles are immovable. Cannot apply forces.\n";
			}
			// First one is movable but the other is not
			else if (m_particles[0]->Movable() && !m_particles[1]->Movable())
			{
				std::cout << "Checking minlength. Only one prticle is movable.\n";
				m_particles[0]->SetPos(m_particles[1]->GetPos() - (diff * m_minLength));
			}
			else
			{
				//m_particles[1]->PosOffset(diff * extra);
				m_particles[1]->SetPos(m_particles[0]->GetPos() - (-diff * m_minLength));
			}
		}
		// If within min and max and not within natural length, simple apply forces
		else
		{
			// Apply force to both particles at each end
			std::cout << "No min or max condition met. Applying forces.\n\n";
			m_particles[0]->AddForce(force);
			m_particles[1]->AddForce(-force);
		}
	}

	// Default 0.2
	void Spring::SetKVal(float k)
	{
		m_kValue = k;
	}

	// Default min 0.0 max 2.0
	void Spring::SetMinAndMaxVal(float min, float max)
	{
		m_minLength = min;
		m_maxLength = max;
	}

	// Default 1.0
	void Spring::SetNaturalLength(float naturalLength)
	{
		m_naturalLength = naturalLength;
	}

	float Spring::GetKVal() const
	{
		return m_kValue;
	}

	float Spring::GetMinVal() const
	{
		return m_minLength;
	}

	float Spring::GetMaxVal() const
	{
		return m_maxLength;
	}

	float Spring::GetNaturalLength() const
	{
		return m_naturalLength;
	}

	void SetMovable()
	{
		
	}

	void SetImmovable()
	{

	}
}
