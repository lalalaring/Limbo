#include "DInputFactory.h"
#include "DInputClass.h"

IInput* DInputFactory::Create()
{
	return new DInputClass();
}