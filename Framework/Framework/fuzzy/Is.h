#ifndef IS_H
#define IS_H

#include "../core/UnaryExpression.h"

namespace fuzzy
{
	template <class T>
	class Is:public UnaryExpression<T> // Interface
	{
		virtual T evaluate(Expression<T>* e) const=0;
	};
}

#endif