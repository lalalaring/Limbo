#pragma once
#include "IFactory.h"
class DSoundFactory :public ISoundFactory
{
public:
	ISound * Create();
};
