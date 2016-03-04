#ifndef ORMAX_H
#define ORMAX_H

#include "Operator.h"

namespace fuzzy
{

	template <class T>
	class OrMax : public Or<T>
	{
	public :
		OrMax();
		virtual ~OrMax(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	OrMax<T>::OrMax() {}

	template <class T>
	T OrMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
		return (l_evaluation > r_evaluation) ? l_evaluation : r_evaluation;
	}
}

#endif