#include "Render.h"

bool NullRender::Create(int32_t windowId, int32_t width, int32_t height)
{
	return true;
}
bool NullRender::Destory()
{
	return true;
}
bool NullRender::Reset(int32_t width, int32_t height)
{
	return true;
}
void NullRender::OnSize(int32_t width, int32_t height)
{
	
}
void NullRender::BeginScene()
{

}
void NullRender::EndScene()
{

}
void NullRender::Draw()
{

}