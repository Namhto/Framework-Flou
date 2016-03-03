#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Is.h"

namespace fuzzy
{

	template <class T>
	class IsTriangle:public Is<T>
	{
	private:
		T min;
		T mid;
		T max;

	public:		
		IsTriangle(const T&, const T&, const T&);
		virtual T getMin() const;
		virtual T getMid() const;
		virtual T getMax() const;
		virtual void setMin(T&);
		virtual void setMid(T&);
		virtual void setMax(T&);
		virtual T evaluate(Expression<T>*) const;
	};


	template <class T>
	IsTriangle<T>::IsTriangle(const T& _min, const T& _mid, const T& _max):
	min(_min),mid(_mid),max(_max)
	{}

	template <class T>
	T IsTriangle<T>::getMin() const {
		return min;
	}

	template <class T>
	T IsTriangle<T>::getMid() const {
		return mid;
	}

	template <class T>
	T IsTriangle<T>::getMax() const {
		return max;
	}

	template <class T>
	void IsTriangle<T>::setMin(T& _min) {
		min=_min;
	}

	template <class T>
	void IsTriangle<T>::setMid(T& _mid) {
		mid=_mid;
	}

	template <class T>
	void IsTriangle<T>::setMax(T& _max) {
		max=_max;
	}

	template <class T>
	T IsTriangle<T>::evaluate(Expression<T>* e) const {
		
		T evaluation = e->evaluate();
		if ((evaluation <= min) || (evaluation >= max)) return 0;
		return (evaluation <= mid) ? ((evaluation - min)/(mid-min)) : ((max - evaluation)/(max-mid));
	}
}

#endif