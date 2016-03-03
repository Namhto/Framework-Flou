#ifndef AGGMAX_H
#define AGGMAX_H

#include"Operator.h"

namespace fuzzy
{

	template <class T>
	class AggMax : public Agg<T>
	{
	public:
		AggMax();
		virtual ~AggMax() {};
		T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	AggMax<T>::AggMax()
	{}

	template <class T>
	T AggMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_eval = l->evaluate();
		T r_eval = r->evaluate();
		return (l_eval > r_eval) ? l_eval : r_eval;
	}
}

#endif