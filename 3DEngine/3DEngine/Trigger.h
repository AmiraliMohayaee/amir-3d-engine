// http://www.codeproject.com/Tips/860245/Trigger-class-for-Cplusplus

#pragma once


#include <iostream>


//namespace Engine
//{
//	template<typename TReturn, typename TParameter, typename TDefaultKey = std::string>
//	
//	class Trigger 
//	{
//		public:
//			typedef boost::function<TReturn (TParameter)> triggerFunction_T;
//			typedef std::map<TDefaultKey, triggerFunction_T> triggerMap_T;
//			typedef std::pair<TDefaultKey, triggerFunction_T> triggerPair_T;
//
//			Trigger(){
//				triggers.reset(new triggerMap_T);
//			};
//
//			virtual ~Trigger(){
//
//			};
//
//			/** Register a class member trigger function.
//			 *
//			 */
//			template<typename TFunction, typename TObject>
//			int addTriggerAcceptor(TDefaultKey name, TFunction f, TObject obj){
//				typename triggerMap_T::iterator it;
//				triggerFunction_T                    trigger = boost::bind(f,obj,_1);
//				it = triggers->find(name);
//				triggers->insert(triggerPair_T(name,trigger));
//				return 0;
//			};
//
//			/** Register a trigger function.
//			 *
//			 */
//			int addTriggerAcceptor(TDefaultKey name, triggerFunction_T f){
//				typename triggerMap_T::iterator it;
//				it = triggers->find(name);
//				triggers->insert(triggerPair_T(name,f));
//				return 0;
//			};
//
//			TReturn raiseTrigger(TDefaultKey name, TParameter param){
//				typename triggerMap_T::iterator it;
//
//				it = triggers->find(name);
//				if(it != triggers->end()){
//					return it->second(param);
//				}
//			};
//
//		private:
//			boost::shared_ptr<triggerMap_T> triggers;
//	};
//}


////// Example of how to use the trigger
//int testfunction(int parameter){
//     return parameter + 10;
//}
//
//int main(int argc, const char **argv){
//     Trigger<int, int> trigger;
//     trigger.addTriggerAcceptor("testfunction", &testfunction);
//     int status = trigger.raiseTrigger("testfunction", 100);
//     std::cout << status << std::endl;
//     return 0;
//}