#ifndef COLLISION_SPHERE_H_INCLDUED
#define COLLISION_SPHERE_H_INCLDUED


#include "MyGL.h"
#include "EventHandler.h"
#include "CollisionMesh.h"
#include "Mgc/MgcDistLin3Tri3.h"
#include "Box3D.h"
#include "SimpleCollisionSystem.h"
#include "Particle.h"
#include "Spring.h"
#include "Cloth.h"
#include "Vec3.h"


namespace Engine
{
	//class Particle;

	class CollisionSphere ///: public GameObject, public EventHandler
	{
	public:
		CollisionSphere();
		~CollisionSphere();

		void Draw();
		void Update(CollisionSphere& otherCS);

		Vec3f& GetPos();
		void SetPos(Vec3f pos);

		float GetRadius() const;
		void SetRadius(float rad);

		// Cheap bounding boxes
		const Box3D &GetSphereBounds();

		// over-riding Keyboard and Motion and key events
		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

		const char* GetTypeName() const;


	private:
		Vec3f m_pos;
		Vec3f m_oldPos;
		float m_radius;
		float m_vel;	// Velocity
		float m_accel;	// Accelleration

		bool m_wasd[4];
	};
}

#endif