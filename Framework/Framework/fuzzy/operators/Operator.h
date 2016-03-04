#ifndef OPERATOR_H
#define OPERATOR_H

#include "../../core/BinaryExpression.h"
#include "../../core/UnaryExpression.h"
#include <cmath>
using namespace core;

namespace fuzzy
{
	/**********************Add**********************/
	template <class T>
	class Add : public BinaryExpression<T>
	{
	public:
		Add();
		virtual ~Add() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
	};

	template <class T>
	Add<T>::Add() {}

	template <class T>
	T Add<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T a = l->evaluate();
		T b = r->evaluate();
		return (a + b);
	}

	/**********************Agg**********************/
	template <class T>
	class Agg : public BinaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	/**********************And**********************/
	template <class T>
	class And :public BinaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	/**********************Not**********************/
	template <class T>
	class Not : public UnaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>*) const = 0;
	};

	/**********************Or**********************/
	template <class T>
	class Or : public BinaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

	/**********************Then**********************/
	template <class T>
	class Then : public BinaryExpression<T>
	{
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};

}

#endif