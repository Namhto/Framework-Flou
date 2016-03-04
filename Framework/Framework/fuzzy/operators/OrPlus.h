#ifndef ORPLUS_H
#define ORPLUS_H

#include "Operator.h"

namespace fuzzy
{

	template <class T>
	class OrPlus : public Or<T>
	{
	public :
		OrPlus();
		virtual ~OrPlus(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	OrPlus<T>::OrPlus() {}

	template <class T>
	T OrPlus<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
		return l_evaluation + r_evaluation;
	}
}

#endif