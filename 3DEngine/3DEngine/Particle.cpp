#include "Particle.h"
#include "Timer.h"
#include "MyGL.h"


namespace Engine
{
	float dt = Timer::Instance()->GetDt();

	Particle::Particle()
	{
		m_mass = 0;
		m_invMass = 0;
		m_pos = Vec3f(0, 0, 0);
		m_vel = Vec3f(0, 0, 0);
	}

	void Particle::UpdateEuler()
	{	
		float dt = Timer::Instance()->GetDt();

		static const Vec3f GRAVITY(0, -0.5f, 0);

		// As mass is inversely proportional to acceleration
		// we'll simply multiply the force instead of deviding
		// the force by mass
		m_acceleration = m_forces * m_invMass;
		//m_acceleration += GRAVITY;
		Vec3f m_oldVel = m_vel;
		m_vel += m_acceleration * dt;
		if (m_forces.y != 0.0f)
		{
			std::cout << "BEFORE: Particle y position is at " << m_pos.y << " .\n";
		}

		// Average Vel multiplied DV by DT
		m_pos += 
			((m_oldVel + m_vel) * 0.5f) * dt;

		if (m_forces.y != 0.0f)
		{
			std::cout << "Particle y position is at " << m_pos.y << " .\n";
		}

		// Resetting force
		m_forces = Vec3f();
	}

	void Particle::UpdateVerlet()
	{
		Vec3f diff = m_pos - m_oldPos +
			m_acceleration * dt * dt;

		m_oldPos = m_pos;
		m_pos += diff;
	}

	void Particle::DrawGL()
	{   
		glPushMatrix();
			glTranslatef(m_pos.x, m_pos.y, m_pos.z);
			glColor3f(0, 1, 1);
			glutSolidCube(0.2f);
		glPopMatrix();
	}


	void Particle::Update()
	{
		//if(m_invMass > 0)
		//{
	
		//}

		if (m_forces.y != 0)
		{
			std::cout << "The force applied to particle on y-axis is " << m_forces.y << ".\n";
		}

		UpdateEuler();
		//UpdateVerlet();

		//TimeStep();
	}

	void Particle::AddForce(Vec3f f)
	{
		m_forces += f;
		//m_acceleration += f / m_invMass;
	}

	void Particle::SetInvMass(float invMass)
	{
		m_invMass = invMass;
	}

	Vec3f& Particle::GetPos()
	{
		return m_pos;
	}

	Vec3f Particle::GetForce()
	{
		return m_forces;
	}

	void Particle::SetPos(const Vec3f& pos)
	{
		m_pos = pos;
	}

	// Resetting Accelleration
	void Particle::ResetAcc()
	{
		m_acceleration = Vec3f(0.0,0.0,0.0);
	}

	// Function for moving a particle along with appropriate damping
	// and accelleration * particle timeSteps
	//void Particle::TimeStep()
	//{
	//	if(m_bMovable)
	//	{
	//		Vec3f temp = m_pos;
	//		m_oldPos = temp;
	//		m_acceleration = Vec3f(0.0,0.0,0.0);
	//		m_pos = m_pos + (m_pos-m_oldPos)*(1.0 - DAMPING) + m_acceleration * TIME_STEPSIZE2;
	//	}
	//}

	// Offsetting position if particle is movable
	void Particle::PosOffset(const Vec3f& offset)
	{
		if(m_bMovable) m_pos += offset;
	}

	// Making particle static
	void Particle::MakeUnmovable()
	{
		m_bMovable = false;
	}

	bool Particle::Movable()
	{
		if (m_invMass > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Vec3f Particle::GetVelocity()
	{
		return m_vel;
	}

	Vec3f Particle::GetAcceleration()
	{
		return m_acceleration;
	}

	const void Particle::AddToNormal(Vec3f& normal)
	{
		normal.Normalize();
		m_accumulatedNormal += normal;
	}

	Vec3f& Particle::GetNormal()
	{ 
		return m_accumulatedNormal;
	}

	float& Particle::GetInvMass()
	{
		return m_invMass;
	}

	void Particle::ResetNormal() 
	{
		m_accumulatedNormal = Vec3f(0.0,0.0,0.0);
	}
}