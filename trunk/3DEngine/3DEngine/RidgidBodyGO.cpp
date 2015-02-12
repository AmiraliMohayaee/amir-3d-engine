#include "RidgidBodyGO.h"
#include "Timer.h"


namespace Engine
{
	RidgidBodyGO::RidgidBodyGO()
	{
		m_collMesh = 0;
	}

	void RidgidBodyGO::AddTorque()
	{
		// sums the torque

	}

	const Box3D& RidgidBodyGO::GetModel() const
	{
		return m_rect;
	}

	void RidgidBodyGO::Update()
	{
		// Finding the new position of the player
		// and calculating the speed
		Vec3f newPos = m_pos + m_vel * Timer::Instance()->GetDt();
		Capsule cap(LineSeg3(newPos, m_pos), 1.0f);
		CollisionMesh::TriPtrs triptrs;
		if (!m_collMesh->Intersects(cap, &triptrs))
		{
			m_pos = newPos;
		}
	}

	void RidgidBodyGO::SetPos(const Vec3f& pos)
	{
		m_pos = pos;
	}
}