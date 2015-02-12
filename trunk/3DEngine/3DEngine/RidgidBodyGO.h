///////////////////////////////////////////////////////////////////////
// Virtual base class for game objects which would contain elements 
// relating to physics and collision
///////////////////////////////////////////////////////////////////////
#pragma once

#include "Vec3.h"
#include "Quaternion.h"
#include "GameObject.h"
#include "Box3D.h"
#include "Vec3.h"
#include <map>


namespace Engine
{
	class RidgidBodyGO : public GameObject
	{
	public:
		RidgidBodyGO();
		virtual ~RidgidBodyGO() { }

		virtual void Update() override;
		virtual void AddTorque();	//torque = CrossProduct(twistingForce, pointOfApplicationOfForce);


		const Box3D& GetModel() const;
		void SetCollisionMesh(CollisionMesh* cm) { m_collMesh = cm; }


		const Vec3f& GetPos() const { return m_pos; }
		const Vec3f& GetVel() const { return m_vel; }
		void SetPos(const Vec3f&);


	protected:
		Box3D m_rect;
		Vec3f m_vel;
		Vec3f m_oldVel;
		Vec3f m_pos;
		Vec3f m_acc;



		float m_angle;

		Quaternion m_rot;

		Vec3f m_2DAngPos;
		Quaternion m_3DAngPos;

		float m_2DAngVel;
		Vec3f m_3DAngVel;

		float m_2DAngAcc;
		Vec3f m_3DAngAcc;

		float m_torque2;
		Vec3f m_torque3;

		CollisionMesh* m_collMesh;
	};

	typedef std::map<int, RidgidBodyGO*> RidgidBodyObjects;
}