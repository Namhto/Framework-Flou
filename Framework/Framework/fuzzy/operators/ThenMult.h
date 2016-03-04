#ifndef THENMULT_H
#define THENMULT_H

#include"Operator.h"

namespace fuzzy
{
	template <class T>
	class ThenMult : public Then<T> 
	{
	public :
		ThenMult();
		virtual ~ThenMult(){};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};


	template <class T>
	ThenMult<T>::ThenMult() {}

	template <class T>
	T ThenMult<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T l_evaluation = l->evaluate();
		T r_evaluation = r->evaluate();
		return (l_evaluation * r_evaluation);
	}

}

#endif