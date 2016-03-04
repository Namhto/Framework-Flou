#ifndef THENMULT_H
#define THENMULT_H

#include"Operator.h"

namespace fuzzy
{
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T>
	{
	public:
		MamdaniDefuzz();
		virtual ~MamdaniDefuzz() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T defuzz() const = 0;
	};


	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() {}

	template <class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		return NULL;
	}

}

#endif