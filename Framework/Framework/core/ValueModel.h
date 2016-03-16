#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H

#include "Expression.h"

namespace core
{

	template <class T>
	class ValueModel : public Expression<T> // Interface
	{
	private:
		T value;

	public:
		virtual T evaluate() const;
		virtual void setValue(const T&);
	};

	template <class T>
	T ValueModel<T>::evaluate() const {
		return value;
	}

	template <class T>
	void ValueModel<T>::setValue(const T& _value) {
		value = _value;
	}
}

#endif