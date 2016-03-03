#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsTrapeze:public Is<T>
	{
	public:		
		IsTrapeze(T&, T&, T&,T&);
		T getMin();
		T getMidMin();
		T getMidMax();
		T getMax();
		void setMin(T&);
		void setMidMin(T&);
		void setMidMax(T&);
		void setMax(T&);
		T evaluate(Expression<T>*) const;

	private:
		T min;
		T midmin;
		T midmax;
		T max;
	};


	template <class T>
	IsTrapeze<T>::IsTrapeze(T& _min, T& _midmin, T& _midmax, T& _max):
	min(_min),midmin(_midmin),midmax(_midmax),max(_max)
	{}

	template <class T>
	T IsTrapeze<T>::getMin()
	{
		return min;
	}

	template <class T>
	T IsTrapeze<T>::getMidMin()
	{
		return midmin;
	}

	template <class T>
	T IsTrapeze<T>::getMidMax()
	{
		return midmax;
	}

	template <class T>
	T IsTrapeze<T>::getMax()
	{
		return max;
	}

	template <class T>
	void IsTrapeze<T>::setMin(T& _min)
	{
		min=_min;
	}

	template <class T>
	void IsTrapeze<T>::setMidMin(T& _mid)
	{
		midmin=_mid;
	}

	template <class T>
	void IsTrapeze<T>::setMidMax(T& _mid)
	{
		midmax=_mid;
	}

	template <class T>
	void IsTrapeze<T>::setMax(T& _max)
	{
		max=_max;
	}

	template <class T>
	T IsTrapeze<T>::evaluate(Expression<T>* e) const
	{
		T ev=e->evaluate();
		if (ev<=min || ev >=max)
			return 0;
		else if (ev>=midmin && ev <=midmax)
			return 1;
		return (ev<=midmin)?((ev-min)/(midmin-min)):((max-ev)/(max-midmax));
	}
}

#endif