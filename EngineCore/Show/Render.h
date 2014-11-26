#include "../pch.h"
#include "../Interface/IRender.h"
class NullRender:public IRender
{
public:
	bool Create(int32_t windowId, int32_t width, int32_t height);
	bool Destory();
	bool Reset(int32_t width, int32_t height);
	//Draw
	void BeginScene();
	void EndScene();
	//int32_t CreateBuffer(void* data, int32_t size);
	//bool DestoryBuffer(int32_t identity);
	//void SetVertex(int32_t identity);
	void Draw();
	//////////////////////////////////////////////////////////////////////////
	void OnSize(int32_t width, int32_t height);
protected:
private:
};