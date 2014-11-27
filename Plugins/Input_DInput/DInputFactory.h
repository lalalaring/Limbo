#pragma once
#include "IFactory.h"
class DInputFactory :public IInputFactory
{
public:
	IInput * Create();
};
