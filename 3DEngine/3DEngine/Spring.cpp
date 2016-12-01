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

	// Initializing both particles
	void Spring::SetParticles(Particle* p1, Particle* p2)
	{
		m_particles[0] = p1;
		m_particles[1] = p2;

		// Checking for particles
		assert(m_particles[0]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		assert(m_particles[1]);

		m_diff = 
			m_particles[1]->GetPos() -
			m_particles[0]->GetPos();

		float m_diffLen = m_diff.Length();
		m_naturalLength = m_diffLen;
	}

	void Spring::CalcRestoring()
	{
		// Get vector between points
		m_diff = 
			m_particles[0]->GetPos() -
			m_particles[1]->GetPos();	
		// The order which the vector is aquired is important otherwise
		// strange negative values not conforming to hook's formula may appear
		
		float m_diffLen = m_diff.Length();

		// Get difference between dist and natural length = x
		float x = m_diffLen - m_naturalLength;

		std::cout << "Cloth natural length is " << m_naturalLength << " .\n";

				// (clamp x ?)
		//if (fabs(m_diffLen) < 0.0001f)	// fabs function returns absolute value of a float
		//{
		//	std::cout << "Could not determine delta length.\n";
		//	return;
		//}
		if ((x < 0.01f) && (x > -0.01f))
		{
			std::cout << "Could not determine delta length.\n";
			return; 
		}

		// Hooke's Law; F = -k x
		m_diff.Normalize();	// Normalizing the vector before doing elasticity check
		m_force = m_diff * ( -m_kValue * x );	// multiplying the float values of K and Dleta L by a Vector

		std::cout << "The delta length value is" << x << ".\n";
		std::cout << "The spring force value is" << m_force.y << ".\n";

		// Vector centrepoint
		//Vec3f CentrPoint = ((m_particles[0]->GetPos() - m_particles[1]->GetPos()) * 0.5f); 

		Vec3f forceHalved = m_force * 0.5;

		if (m_force.y > 3.0f)
		{
			m_force.x -= 2.0f;
			m_force.y -= 2.0f;
			m_force.z -= 2.0f;
		}

		m_particles[0]->AddForce(forceHalved);
		m_particles[1]->AddForce(-forceHalved);
	}

	// Updating both particles
	void Spring::Update()
	{
		std::cout << "Spring natural length is " << m_naturalLength << " .\n";
		
		CalcRestoring();
	}

	// Default 0.2
	void Spring::SetKVal(float k)
	{
		m_kValue = k;
	}
	
	void Spring::SetMinVal(float min)
	{
		m_minLength = min;
	}
		
	void Spring::SetMaxVal(float max)
	{
		m_maxLength = max;
	}

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

	void Spring::SetMovable()
	{
		
	}

	void Spring::SetImmovable()
	{

	}
}




		//m_centrePoint = (m_diff * (m_diffLen * 0.5));

		//// New length vectors pointing towards and away
		//m_newLengthPositive = m_diff * (m_maxLength * 0.5);
		//m_newLengthNegative = m_diff * -(m_maxLength * 0.5);

		//// Damping
		//// enforcing min and maxlengths and clamping
		//if (m_diffLen > m_maxLength)
		//{
		//	//float extra = diffLen - m_maxLength;
		//	//Vec3f newLength = diff * (extra/2);

		//	// checking if particle is immovable or not
		//	// decreasing the length if it goes above maxlength and if movable
		//	// if (particle  is movable)
		//	// diff = (maxlength - (particle0 - particle 1)
		//	// same as above for minlength, except in negative distance

		//	// Both movable
		//	if (m_particles[0]->Movable() && m_particles[1]->Movable())
		//	{
		//		std::cout << "Checking maxlength. Both objects are movable, offsetting position of "<<
		//			 "both particles.\n";

		//		m_particles[0]->SetPos(m_centrePoint - (m_newLengthNegative));
		//		m_particles[1]->SetPos(m_centrePoint + (m_newLengthPositive));



		//		// Pos Offsetting for some testing
		//		//m_particles[0]->PosOffset(-newLength);
		//		//m_particles[1]->PosOffset(newLength);
		//	}
		//	// If both immovable
		//	else if (!m_particles[0]->Movable() && !m_particles[1]->Movable())
		//	{
		//		// Both immovable, Do nothing
		//		std::cout << "Checking Maxlength. Both particles are immovable.\n";
		//	}
		//	// First one is movable but the other is not
		//	else if (m_particles[0]->Movable() && !m_particles[1]->Movable())
		//	{
		//		std::cout << "Checking Maxlength. Only the first prticle is movable.\n";
		//		m_particles[0]->SetPos(m_particles[1]->GetPos() - (m_diff * m_maxLength));
		//	}
		//	else
		//	{
		//		//m_particles[1]->PosOffset(diff * extra);
		//		std::cout << "Checking Maxlength. Only the second prticle is movable.\n";
		//		m_particles[1]->SetPos(m_particles[0]->GetPos() - (-m_diff * m_maxLength));
		//	}
		//}
		//else if (m_diffLen < m_minLength)
		//{
		//	//float extra = m_diffLen - m_maxLength;
		//	//Vec3f newLength = m_diff * (extra/2);

		//	// Both movable
		//	if (m_particles[0]->Movable() && m_particles[1]->Movable())
		//	{
		//		std::cout << "Checking minlength. Both particles are movable.";
		//		// Damping
		//		//Vec3f CentrPoint = ((m_particles[0]->GetPos() - m_particles[1]->GetPos()) * 0.5f); 

		//		m_particles[0]->SetPos(m_centrePoint - (m_diff * (m_minLength * 0.5f)));
		//		m_particles[1]->SetPos(m_centrePoint + (m_diff * (m_minLength * 0.5f)));
		//		
		//		// Pos Offsetting for some testing
		//		//m_particles[0]->PosOffset(-newLength);
		//		//m_particles[1]->PosOffset(newLength);
		//	}

		//	// If both immovable
		//	else if (!m_particles[0]->Movable() && !m_particles[1]->Movable())
		//	{
		//		// Both immovable, Do nothing
		//		std::cout << "Checking minlength. Both particles are immovable. Cannot apply forces.\n";
		//	}
		//	// First one is movable but the other is not
		//	else if (m_particles[0]->Movable() && !m_particles[1]->Movable())
		//	{
		//		std::cout << "Checking minlength. Only one prticle is movable.\n";
		//		m_particles[0]->SetPos(m_particles[1]->GetPos() - (m_diff * m_minLength));
		//	}
		//	else
		//	{
		//		//m_particles[1]->PosOffset(diff * extra);
		//		m_particles[1]->SetPos(m_particles[0]->GetPos() - (-m_diff * m_minLength));
		//	}
		//}
		//// If within min and max and not within natural length, simple apply forces
		//else /*if (!m_diffLen > m_maxLength || !m_diffLen < m_minLength)*/
		//{
		//	// Apply force to both particles at each end
		//	std::cout << "No min or max condition met. Applying forces.\n\n";
		//	m_particles[0]->AddForce(m_force);
		//	m_particles[1]->AddForce(-m_force);
		//}