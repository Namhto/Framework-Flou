#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H

#include "BinaryExpression.h"

namespace core
{

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T> // Interface
	{
	private:
		BinaryExpression<T>* op;
		Expression<T>* left, right;

	public:
		virtual T evaluate() const;
		virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if ((left != nullptr) && (right != nullptr))
			return evaluate(left, right);
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const {
		if (op != nullptr)
			return op->evaluate(l, r);
	}
}
#endif