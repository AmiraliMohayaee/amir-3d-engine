#ifndef TIMER_H
#define TIMER_H

namespace Engine
{
	//using Singleton design pattern
	class Timer
	{
	private:
		Timer();
		Timer(const Timer&); //copy ctor
		Timer& operator=(const Timer&); // assignment opperator

	public:
		static Timer* Instance();
		float GetDt() const;
		void Update();

	private:
		float m_dt;
	};
}

#endif