#ifndef FACTORY_H
#define FACTORY_H

#include "Singleton.h"
#include <map>
#include <string>
#include <assert.h>
#include "GameObject.h"

namespace Engine
{
	template <class T>
	class Factory : public NonCopyable
	{
	public:
		typedef T* (*Function)();

		T* Create(const std::string& typeName) 
		{
			// Look up a function: name is key
			Function f = m_map[typeName];
			assert(f);
			if (f)
			{
				// Call the function
				return f();
			}
			return 0;
		}

		bool AddType(
			const std::string& typeName,
			Function f)
		{
			m_map[typeName] = f;
			return true;
		}

	private:
		typedef std::map<std::string, Function> FactoryMap;

		FactoryMap m_map;
	};
	typedef Singleton<Factory<GameObject> > TheGameObjectFactory;

}

#endif