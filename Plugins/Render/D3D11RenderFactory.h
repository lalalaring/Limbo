#pragma once
#include "IFactory.h"
class D3D11RenderFactory:public IRenderFactory
{
public:
	IRender* Create();
};

