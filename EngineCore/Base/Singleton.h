//////////////////////////////////////////////////////////////////////////
//Common Cpp Class
//
//Author:YanYuHongChen
//2014-04-14
//////////////////////////////////////////////////////////////////////////
#ifndef _HC_SINGLETON_H_
#define _HC_SINGLETON_H_
#include <memory>

namespace Limbo
{

	template <typename T>
	class Singleton
	{
	public:
		static inline T* Instance();

	protected:
		Singleton(){}
		~Singleton(){}
		Singleton(const Singleton&){}
		Singleton& operator= (const Singleton&){}

		static std::auto_ptr<T> _instance;
	};

	template <typename T>
	std::auto_ptr<T> Singleton<T>::_instance;

	template <typename T>
	inline T* Singleton<T>::Instance()
	{
		if (0 == _instance.get()) {
			_instance.reset(new T);
		}

		return _instance.get();
	}

}//namespace girlfriend
#endif//_HC_SINGLETON_H_