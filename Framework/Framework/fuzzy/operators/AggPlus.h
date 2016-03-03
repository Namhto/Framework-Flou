#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Operator.h"

namespace fuzzy
{

	template <class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus();
		virtual ~AggPlus() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	AggPlus<T>::AggPlus()
	{}

	template <class T>
	T AggPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		
		T l_eval = l->evaluate();
		T r_eval = r->evaluate();
		return (l_eval + r_eval);
	}
}

#endif