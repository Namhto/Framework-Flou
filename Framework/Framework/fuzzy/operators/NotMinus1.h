#ifndef THENMIN_H
#define THENMIN_H

#include"Operator.h"

namespace fuzzy
{

	template <class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1();
		virtual ~ThenMin() {};
		virtual T evaluate(Expression<T>*) const;
	};

	template <class T>
	NotMinus1<T>::NotMinus1() {}

	template <class T>
	T NotMinus1<T>::evaluate(Expression<T>* e) const {
		T evaluation = e->evaluate();
		return (1 - evaluation);
	}

}
#endif