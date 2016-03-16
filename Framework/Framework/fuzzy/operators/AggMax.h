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
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	AggMax<T>::AggMax() {}

	template <class T>
	T AggMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
	 	return (l_evaluation > r_evaluation) ? l_evaluation : r_evaluation;
	}
}

#endif