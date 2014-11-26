#include "D3D11RenderFactory.h"
#include "D3D11Render.h"

IRender* D3D11RenderFactory::Create()
{
	return new D3D11Render();
}