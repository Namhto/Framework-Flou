#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include "Is.h"

namespace core
{

	template <class T>
	class IsGaussian:public Is<T>
	{
	public:		
		IsGaussian(T&, T&);
		T getSig();
		T getMax();
		void setSig(T&);
		void setMax(T&);
		T evaluate(Expression<T>*) const;

	private:
		T sig;
		T max;
	};


	template <class T>
	IsGaussian<T>::IsGaussian(T& _sig, T& _max):
	sig(_sig),max(_max)
	{}

	template <class T>
	T IsGaussian<T>::getSig()
	{
		return sig;
	}


	template <class T>
	T IsGaussian<T>::getMax()
	{
		return max;
	}

	template <class T>
	void IsGaussian<T>::setSig(T& _sig)
	{
		sig=_sig;
	}


	template <class T>
	void IsGaussian<T>::setMax(T& _max)
	{
		max=_max;
	}

	template <class T>
	T IsGaussian<T>::evaluate(Expression<T>* e) const
	{
		T ev=e->evaluate();
		return exp((-pow(ev-max,2))/(2*pow(sig,2)));
	}
}

#endif