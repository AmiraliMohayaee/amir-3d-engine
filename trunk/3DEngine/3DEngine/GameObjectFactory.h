#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include "Singleton.h"
#include "GameObject.h"
#include <map>
#include <string>
#include "Factory.h"

namespace Engine
{
	class GameObject;

	typedef Factory<GameObject> GameObjectFactory;

	typedef Singleton<GameObjectFactory> ObjectFactory;
}

#endif