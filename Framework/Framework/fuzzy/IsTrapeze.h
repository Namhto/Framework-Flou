#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Is.h"
#include <cmath>

namespace fuzzy
{

	template <class T>
	class IsTrapeze:public Is<T>
	{
	private:
		T min;
		T mid_min;
		T mid_max;
		T max;

	public:		
		IsTrapeze(const T&, const T&, const T&, const T&);
		virtual T getMin() const;
		virtual T getMidMin() const;
		virtual T getMidMax() const;
		virtual T getMax() const;
		virtual void setMin(T&);
		virtual void setMidMin(T&);
		virtual void setMidMax(T&);
		virtual void setMax(T&);
		virtual T evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(const T& _min, const T& _mid_min, const T& _mid_max, const T& _max):
	min(_min),mid_min(_mid_min),mid_max(_mid_max),max(_max)
	{}

	template <class T>
	T IsTrapeze<T>::getMin() const {
		return min;
	}

	template <class T>
	T IsTrapeze<T>::getMidMin() const {
		return mid_min;
	}

	template <class T>
	T IsTrapeze<T>::getMidMax() const {
		return mid_max;
	}

	template <class T>
	T IsTrapeze<T>::getMax() const {
		return max;
	}

	template <class T>
	void IsTrapeze<T>::setMin(T& _min) {
		min=_min;
	}

	template <class T>
	void IsTrapeze<T>::setMidMin(T& _mid) {
		mid_min=_mid;
	}

	template <class T>
	void IsTrapeze<T>::setMidMax(T& _mid) {
		mid_max=_mid;
	}

	template <class T>
	void IsTrapeze<T>::setMax(T& _max) {
		max=_max;
	}

	template <class T>
	T IsTrapeze<T>::evaluate(Expression<T>* e) const {
		
		T evaluation = e->evaluate();
		
		if ((evaluation <= min) || (evaluation >= max)) return 0;
		
		else {
			if ((evaluation >= mid_min) && (evaluation <= mid_max)) return 1;
		}
		
		return (evaluation <= mid_min) ? ((evaluation - min) / (mid_min - min)) : ((max - evaluation) / (max - mid_max));
	}
}

#endif