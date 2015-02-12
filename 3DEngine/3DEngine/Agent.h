#ifndef AGENT_H
#define AGENT_H

#include "Vec3.h"
#include "SteeringBehaviour.h"
#include "Seek.h"
#include "AgentGroup.h"
#include <map>
#include <cmath>


//to do add inverse mass
//add maxSpeed squared
//add maxForce squared

namespace Engine
{
	class Compare
	{
	public:
		bool operator()(const std::string& a, const std::string& b)
		{
			return a.size() < b.size() ? true : false;
		}
	};

	class Agent
	{
	public:
		Agent();
		Agent(float mass, float maxSpeed, float maxForce, float maxTurnRate, Agent* target);
		~Agent();

		// Amir's functions
		void DecideBehaviour();
		void ApplyForce();

		// Marco's VVV
		void AddSteeringBehaviour(SteeringBehaviour* s);
		void RemoveSteeringBehaviour(const std::string& name);

		//setters and getters
		void SetMass(float m) {m_mass = m; m_inverseMass = 1.0f / m_mass;}
		void SetMaxSpeed(float s) {m_maxSpeed = s; m_maxSpeedSquared = std::pow(m_maxSpeed, 2.0f);}
		void SetMaxForce(float f) { m_maxForce = f; m_maxForceSquared = std::pow(m_maxForce, 2.0f);}
		void SetMaxTurnRate(float t) {m_maxTurnRate = t;}
		void SetTarget(Agent* t) {m_target = t;}
		void SetPos(const Vec3f& p) {m_pos = p;}

		float GetMass() const {return m_mass;}
		float GetMaxSpeed() const {return m_maxSpeed;}
		float GetMAxForce() const {return m_maxForce;}
		float GetMaxTurnRate() const {return m_maxTurnRate;}
		Agent* GetTarget() {return m_target;}
		const Vec3f& GetPos() const {return m_pos;}
		float GetSpeed() const {return m_vel.Length();}
		float GetSpeedSquared() const {return m_vel.SqrLength();}

		void Draw();
		void Update();

	private:
		typedef std::pair<SteeringBehaviour*, float> 
			SteerBehaviourAndWeight;

		typedef std::vector<Agent*> m_ourNeighbours;

		typedef std::map<std::string, SteerBehaviourAndWeight> BehaviourMap;

		Seek m_seek;

		/*Flee m_flee;*/

		// Down here is where Marco left his marko
		float m_mass;
		float m_inverseMass;
		float m_maxSpeed;
		float m_maxSpeedSquared;
		float m_maxForce;
		float m_maxForceSquared;
		float m_maxTurnRate;

		Vec3f m_pos;
		Vec3f m_vel;
		Vec3f m_heading;
		Vec3f m_side;

		Agent* m_target;

		typedef std::map <std::string, SteeringBehaviour*, Compare> SteeringBehaviourMap;
		SteeringBehaviourMap m_steeringBehaviourMap;
	};
}

#endif