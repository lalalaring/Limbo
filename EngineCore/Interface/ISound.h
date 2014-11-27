#pragma once
#include "IInterface.h"
class ISound:public IInterface
{
public:
	virtual void Create() = 0;
	virtual void Destory() = 0;
protected:
private:
};