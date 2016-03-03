#ifndef ISTRAPEZERIGHT_H
#define ISTRAPEZERIGHT_H

#include "Is.h"

namespace fuzzy
{

	template <class T>
	class IsTrapezeRight:public Is<T>
	{
	private:
		T min;
		T mid;
		T max;

	public:		
		IsTrapezeRight(const T&, const T&, const T&);
		virtual T getMin() const;
		virtual T getMid() const;
		virtual T getMax() const;
		virtual void setMin(T&);
		virtual void setMid(T&);
		virtual void setMax(T&);
		virtual T evaluate(Expression<T>*) const;
	};

	template <class T>
	IsTrapezeRight<T>::IsTrapezeRight(const T& _min, const T& _mid, const T& _max):
	min(_min),mid(_mid),max(_max)
	{}

	template <class T>
	T IsTrapezeRight<T>::getMin() const {
		return min;
	}

	template <class T>
	T IsTrapezeRight<T>::getMid() const {
		return mid;
	}

	template <class T>
	T IsTrapezeRight<T>::getMax() const {
		return max;
	}

	template <class T>
	void IsTrapezeRight<T>::setMin(T& _min) {
		min=_min;
	}

	template <class T>
	void IsTrapezeRight<T>::setMid(T& _mid) {
		mid=_mid;
	}

	template <class T>
	void IsTrapezeRight<T>::setMax(T& _max) {
		max=_max;
	}

	template <class T>
	T IsTrapezeRight<T>::evaluate(Expression<T>* e) const {
		
		T evaluation = e->evaluate();
		if ((evaluation <= min) || (evaluation >= max)) return 0;
		
		return (evaluation >= mid) ? 1 : ((evaluation-min)/(mid-min));
	}
}

#endif