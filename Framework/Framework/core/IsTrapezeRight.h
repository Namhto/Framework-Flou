#ifndef ISTRAPEZERIGHT_H
#define ISTRAPEZERIGHT_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsTrapezeRight:public Is<T>
	{
	public:		
		IsTrapezeRight(T&, T&,T&);
		T getMin();
		T getMid();
		T getMax();
		void setMin(T&);
		void setMid(T&);
		void setMax(T&);
		T evaluate(Expression<T>*) const;

	private:
		T min;
		T mid;
		T max;
	};


	template <class T>
	IsTrapezeRight<T>::IsTrapezeRight(T& _min, T& _mid, T& _max):
	min(_min),mid(_mid),max(_max)
	{}

	template <class T>
	T IsTrapezeRight<T>::getMin()
	{
		return min;
	}

	template <class T>
	T IsTrapezeRight<T>::getMid()
	{
		return mid;
	}

	template <class T>
	T IsTrapezeRight<T>::getMax()
	{
		return max;
	}

	template <class T>
	void IsTrapezeRight<T>::setMin(T& _min)
	{
		min=_min;
	}

	template <class T>
	void IsTrapezeRight<T>::setMid(T& _mid)
	{
		mid=_mid;
	}

	template <class T>
	void IsTrapezeRight<T>::setMax(T& _max)
	{
		max=_max;
	}

	template <class T>
	T IsTrapezeRight<T>::evaluate(Expression<T>* e) const
	{
		T ev=e->evaluate();
		if (ev<=min || ev >=max)
			return 0;
		return (ev>=mid)?1:((ev-min)/(mid-min));
	}
}

#endif