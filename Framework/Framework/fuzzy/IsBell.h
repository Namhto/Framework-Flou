#ifndef ISBELL_H
#define ISBELL_H

#include "Is.h"
#include <cmath>

namespace fuzzy
{

	template <class T>
	class IsBell:public Is<T>
	{
	private:
		T min;
		T mid;
		T center;

	public:		
		IsBell(const T&, const T&, const T&);
		virtual T getMin() const;
		virtual T getMid() const;
		virtual T getCenter() const;
		virtual void setMin(T&);
		virtual void setMid(T&);
		virtual void setCenter(T&);
		virtual T evaluate(Expression<T>*) const;
	};


	template <class T>
	IsBell<T>::IsBell(const T& _min, const T& _mid, const T& _center):
	min(_min),mid(_mid),center(_center)
	{}

	template <class T>
	T IsBell<T>::getMin() const {
		return min;
	}

	template <class T>
	T IsBell<T>::getMid() const {
		return mid;
	}

	template <class T>
	T IsBell<T>::getCenter() const {
		return center;
	}

	template <class T>
	void IsBell<T>::setMin(T& _min) {
		min=_min;
	}

	template <class T>
	void IsBell<T>::setMid(T& _mid) {
		mid=_mid;
	}

	template <class T>
	void IsBell<T>::setCenter(T& _center) {
		center=_center;
	}

	template <class T>
	T IsBell<T>::evaluate(Expression<T>* e) const {
		T evaluation = e->evaluate();
		return 1/(1+(pow((abs((evaluation - center)/min)),(2*mid))));
	}
}

#endif