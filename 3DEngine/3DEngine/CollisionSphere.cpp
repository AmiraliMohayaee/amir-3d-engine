#include "CollisionSphere.h"


namespace Engine
{
	CollisionSphere::CollisionSphere()
	{
		m_radius = 1;
		m_pos.x = 3;
		m_pos.y = 0;
		m_pos.z = 0;

		m_vel = 0.01;
		m_accel = 0.0f;

		for (int i = 0; i < 4; i++)
		{
			m_wasd[i] = false;
		}
	}

	CollisionSphere::~CollisionSphere()
	{

	}

	Vec3f& CollisionSphere::GetPos()
	{
		return m_pos;
	}

	void CollisionSphere::SetPos(Vec3f pos)
	{
		m_pos.x = pos.x;
		m_pos.y = pos.y;
		m_pos.z = pos.z;
	}

	float CollisionSphere::GetRadius() const
	{
		return m_radius;
	}

	void CollisionSphere::SetRadius(float rad)
	{
		m_radius = rad;
	}

	void CollisionSphere::Draw()
	{
		//glPushMatrix();
		//	glTranslatef(0, 0, 0);
		//	glutWireSphere(1, 10, 10);
		//glPopMatrix();

		glPushMatrix();
			glTranslatef(m_pos.x, m_pos.y, m_pos.z);
			glutWireSphere(1.0f, 10, 10);
		glPopMatrix();
	}

	void CollisionSphere::Update(CollisionSphere& otherCS)
	{
		// // Check for each particle in the cloth against the position of the sphere
		// For each particle -> vec = sphere pos - particle pos
		// rad squred & vec.len squared 
		// vec.leng    if vec.len - radius then they are colliding so that particles move into the
		// edge of the sphere and not inside
		
		//SetPos(
		m_pos.x += 0.01;
		std::cout << "X Pos is " << m_pos.x << "\n";
		// particle pos = sphere pos + vec (if normalized) * radius
		//glPushMatrix();
			//glTranslatef(m_pos.x += 0.01, 0, 0
		//glPopMatrix();
		
		float dist;
		float radii;
		//m_vel = (

		radii = otherCS.GetRadius() + GetRadius();
		dist = otherCS.GetRadius() - GetRadius();

		if (dist < radii)
		{
			std::cout << "Collision check!\n";
		}


		Vec3f mov;
		if (m_wasd[0])
		{
			//mov += SetPos(
			//mov += Vec3f(0, 1, 0);
		}

		if (m_wasd[1])
		{
			
		}

		if (m_wasd[2])
		{
			
		}

		if (m_wasd[3])
		{
			
		}
	}


	void CollisionSphere::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_w)
		{
			m_wasd[0] = (k.state == SDL_PRESSED);
		}
	
		if (k.keysym.sym == SDLK_a)
		{
			m_wasd[1] = (k.state == SDL_PRESSED);
		}

		if (k.keysym.sym == SDLK_s)
		{
			m_wasd[2] = (k.state == SDL_PRESSED);
		}
	
		if (k.keysym.sym == SDLK_d)
		{
			m_wasd[3] = (k.state == SDL_PRESSED);
		}
	}

	const char* CollisionSphere::GetTypeName() const
	{
		return ("CollSphere");
	}
}