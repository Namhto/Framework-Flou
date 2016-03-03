#ifndef ISTRAPEZELEFT_H
#define ISTRAPEZELEFT_H

#include "Is.h"

namespace fuzzy
{

	template <class T>
	class IsTrapezeLeft:public Is<T>
	{
	private:
		T min;
		T mid;
		T max;

	public:		
		IsTrapezeLeft(const T&, const T&, const T&);
		virtual T getMin() const;
		virtual T getMid() const;
		virtual T getMax() const;
		virtual void setMin(T&);
		virtual void setMid(T&);
		virtual void setMax(T&);
		virtual T evaluate(Expression<T>*) const;
	};


	template <class T>
	IsTrapezeLeft<T>::IsTrapezeLeft(const T& _min, const T& _mid, const T& _max):
	min(_min),mid(_mid),max(_max)
	{}

	template <class T>
	T IsTrapezeLeft<T>::getMin() const {
		return min;
	}

	template <class T>
	T IsTrapezeLeft<T>::getMid() const {
		return mid;
	}

	template <class T>
	T IsTrapezeLeft<T>::getMax() const {
		return max;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMin(T& _min) {
		min=_min;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMid(T& _mid) {
		mid=_mid;
	}

	template <class T>
	void IsTrapezeLeft<T>::setMax(T& _max) {
		max=_max;
	}

	template <class T>
	T IsTrapezeLeft<T>::evaluate(Expression<T>* e) const {
		
		T evaluation = e->evaluate();
		if ((evaluation <= min) || (evaluation >= max)) return 0;
		
		return (evaluation <= mid) ? 1 : ((max-evaluation)/(max-mid));
	}
}

#endif