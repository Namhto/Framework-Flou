#ifndef ISTRAPEZELEFT_H
#define ISTRAPEZELEFT_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsTrapezeLeft:public Is<T>
	{
	public:		
		IsTrapezeLeft(T&, T&,T&);
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
	IsTrapezeLeft<T>::IsTrapezeLeft(T& _min, T& _mid, T& _max):
	min(_min),mid(_mid),max(_max)
	{}

	template <class T>
	T IsTrapezeLeft<T>::getMin()
	{
		return min;
	}

	template <class T>
	T IsTrapezeLeft<T>::getMid()
	{
		return mid;
	}

	template <class T>
	T IsTrapezeLeft<T>::getMax()
	{
		return max;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMin(T& _min)
	{
		min=_min;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMid(T& _mid)
	{
		mid=_mid;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMax(T& _max)
	{
		max=_max;
	}

	template <class T>
	T IsTrapezeLeft<T>::evaluate(Expression<T>* e) const
	{
		T ev=e->evaluate();
		if (ev<=min || ev >=max)
			return 0;
		return (ev<=mid)?1:((max-ev)/(max-mid));
	}
}

#endif