#ifndef PHYSICS_DEMO_STATE_H
#define PHYSICS_DEMO_STATE_H

#include "GameState.h"
#include "Non-Copyable.h"
#include "Singleton.h"
#include "Car.h"
#include "FontManager.h"
#include "Cloth.h"
#include "Particle.h"
#include "Spring.h"
#include "Cloth.h"

namespace Engine
{
	class PhysicsDemoState : public GameState, public NonCopyable
	{
	public:
		PhysicsDemoState();
		virtual void Draw();
		virtual void Update();
		virtual void OnActivated() override;
		virtual void OnDeActivated() override;

		virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

	private:
		//FontManager text;
		//GLuint texId;

		Particle m_partImmovable;
		Particle m_partMovable;
		Spring m_spring;
		Cloth m_cloth;
	};

	typedef Singleton<PhysicsDemoState> ThePhysicsDemoState;
}


#endif

