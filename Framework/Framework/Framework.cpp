// Framework.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "core/IsTriangle.h"
#include <iostream>

int main()
{
	core::IsTriangle<float> t(-5, 0, 5);
	std::cout << t.getMin() << ", " << t.getMid() << " ," << t.getMax();
	return 0;
}

