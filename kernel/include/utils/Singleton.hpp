/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_UTILS_SINGLETON_HPP_
#define _WRAP_KRN_UTILS_SINGLETON_HPP_

namespace wrap{

	template<class T>
	class Singleton{
	public:
		static T& Instance(){
			static T _instance;
			return _instance;
		}

	protected:
		Singleton(){}
		~Singleton(){}

	private:
		Singleton(const Singleton&);
		Singleton& operator =(const Singleton&);
	};

}

#endif
