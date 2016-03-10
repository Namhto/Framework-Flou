#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "BinaryExpression.h"

namespace core
{

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T> // Interface
	{
	private:
		BinaryExpression<T> op;
		Expression<T> left, right;

	public:
		virtual T evaluate() const;
		virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
	};

	template <class T>
	T ValueModel<T>::evaluate() const {
		return T;
	}

	template <class T>
	void ValueModel<T>::setValue(const T& _value) {
		value = _value;
	}
}
#endif