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
	}

	void Particle::UpdateEuler()
	{
		float dt = Timer::Instance()->GetDt();
	
		Vec3f m_oldVel = m_vel;

		m_vel += m_acceleration * dt;
		////m_vel *= 0.9999f;

		// Average Vel multiplied by DT
		m_pos += 
			(m_oldVel + m_vel) * dt * 0.5f;

		std::cout << "Particle x position is at " << m_pos.x << " .\n";
		std::cout << "Particle y position is at " << m_pos.y << " .\n";
		std::cout << "Particle z position is at " << m_pos.z << " .\n";
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
		static const Vec3f GRAVITY(0, -0.5f, 0);

		m_forces += GRAVITY;
		//m_acceleration = m_forces * m_invMass;

		//if(m_invMass > 0)
		//{
		//	m_acceleration += GRAVITY;
		//}

		m_forces = Vec3f();


		UpdateEuler();
		//UpdateVerlet();

		//TimeStep();
	}

	void Particle::AddForce(Vec3f f)
	{
		m_forces += f;
		//m_acceleration += f / m_mass;
	}

	void Particle::SetInvMass(float invMass)
	{
		m_invMass = invMass;
	}

	Vec3f& Particle::GetPos()
	{
		return m_pos;
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