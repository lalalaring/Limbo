#pragma once
#include "IInterface.h"
class IInput:public IInterface
{
public:
	virtual void Create() = 0;
	virtual void Destory() = 0;

	virtual int GetKeyState(int  Key) = 0;
protected:
private:
};