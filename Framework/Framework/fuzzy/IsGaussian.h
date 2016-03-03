#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include "Is.h"
#include <cmath>

namespace fuzzy
{

	template <class T>
	class IsGaussian:public Is<T>
	{
	private:
		T sig;
		T max;

	public:		
		IsGaussian(const T&, const T&);
		virtual T getSig() const;
		virtual T getMax() const;
		virtual void setSig(T&);
		virtual void setMax(T&);
		virtual T evaluate(Expression<T>*) const;
	};

	template <class T>
	IsGaussian<T>::IsGaussian(const T& _sig, const T& _max):
	sig(_sig),max(_max)
	{}

	template <class T>
	T IsGaussian<T>::getSig() const {
		return sig;
	}

	template <class T>
	T IsGaussian<T>::getMax() const {
		return max;
	}

	template <class T>
	void IsGaussian<T>::setSig(T& _sig) {
		sig=_sig;
	}


	template <class T>
	void IsGaussian<T>::setMax(T& _max) {
		max=_max;
	}

	template <class T>
	T IsGaussian<T>::evaluate(Expression<T>* e) const {
		T evaluation = e->evaluate();
		return exp((-pow(evaluation - max,2))/(2*pow(sig,2)));
	}
}

#endif