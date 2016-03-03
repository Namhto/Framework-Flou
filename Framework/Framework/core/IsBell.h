#ifndef ISBELL_H
#define ISBELL_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsBell:public Is<T>
	{
	public:		
		IsBell(T&, T&,T&);
		T getMin();
		T getMid();
		T getCenter();
		void setMin(T&);
		void setMid(T&);
		void setCenter(T&);
		T evaluate(Expression<T>*) const;

	private:
		T min;
		T mid;
		T center;
	};


	template <class T>
	IsBell<T>::IsBell(T& _min, T& _mid, T& _center):
	min(_min),mid(_mid),center(_center)
	{}

	template <class T>
	T IsBell<T>::getMin()
	{
		return min;
	}

	template <class T>
	T IsBell<T>::getMid()
	{
		return mid;
	}

	template <class T>
	T IsBell<T>::getCenter()
	{
		return center;
	}

	template <class T>
	void IsBell<T>::setMin(T& _min)
	{
		min=_min;
	}

	template <class T>
	void IsBell<T>::setMid(T& _mid)
	{
		mid=_mid;
	}

	template <class T>
	void IsBell<T>::setCenter(T& _center)
	{
		center=_center;
	}

	template <class T>
	T IsBell<T>::evaluate(Expression<T>* e) const
	{
		T ev=e->evaluate();
		return 1/(1+(pow((abs((ev-center)/min)),(2*mid))));
	}
}

#endif