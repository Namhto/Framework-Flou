#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsTriangle:public Is<T>
	{
	public:		
		IsTriangle(const T&, const T&, const T&);
		T getMin() const;
		T getMid() const;
		T getMax() const;
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
		T ev=e->evaluate();
		if (ev<=min || ev >=max) return 0;
		return (ev<=mid)?((ev-min)/(mid-min)):((max-ev)/(max-mid));
	}
}

#endif