#ifndef IS_H
#define IS_H

#include "UnaryExpression.h"

namespace core
{

	template <class T>
	class Is:public UnaryExpression<T> // Interface
	{
		virtual T evaluate(Expression<T>* e) const=0;
	};
}

//TOTO
#endif