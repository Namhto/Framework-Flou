#ifndef ANDMIN_H
#define ANDMIN_H

#include"Operator.h"

namespace fuzzy
{

	template <class T>
	class AndMin : public And<T>
	{
	public :
		AndMin();
		virtual ~AndMin(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};
	
	template <class T>
	AndMin<T>::AndMin() {}

	template <class T>
	T AndMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
		return (l_evaluation < r_evaluation) ? l_evaluation : r_evaluation;
	}

}
#endif