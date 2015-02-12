#ifndef STEERING_BEHAVIOUR_H_INCLUDED
#define STEERING_BEHAVIOUR_H_INCLUDED

#include "SteeringBehaviour.h"

namespace Engine
{
	class Seek : public SteeringBehaviour
	{
	public:
		void Update(Agent* parent, Vec3f* force);
		const char* GetTypeName() const {return "Seek";}
	};
}

#endif