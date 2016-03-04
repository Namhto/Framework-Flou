#ifndef ANDMULT_H
#define ANDMULT_H

#include"Operator.h"

namespace fuzzy
{
	
	template <class T>
	class AndMult : public And<T>
	{
	public :
		AndMult();
		virtual ~AndMult(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};


	template <class T>
	AndMult<T>::AndMult() {}

	template <class T>
	T AndMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation=l->evaluate();
		T r_evaluation =r->evaluate();
		return (l_evaluation * r_evaluation);
	}

}

#endif