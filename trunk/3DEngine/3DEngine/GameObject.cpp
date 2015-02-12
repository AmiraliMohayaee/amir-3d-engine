#include "GameObject.h"
#include "Box3D.h"
#include "Timer.h"


namespace Engine
{
	GameObject::GameObject()
	{
		static int id = 0;
		m_id = id;
		id++;
	}
}