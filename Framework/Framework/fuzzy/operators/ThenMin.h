#ifndef THENMIN_H
#define THENMIN_H

#include"Operator.h"

namespace fuzzy
{

	template <class T>
	class ThenMin : public Then<T>
	{
	public :
		ThenMin();
		virtual ~ThenMin(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};
	
	template <class T>
	ThenMin<T>::ThenMin() {}

	template <class T>
	T ThenMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
		return (l_evaluation < r_evaluation) ? l_evaluation : r_evaluation;
	}

}
#endif