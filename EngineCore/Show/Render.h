#include "../pch.h"

class Render
{
public:
	bool Create();
	bool Destory();
	bool Reset();
	//Draw
	void BeginScene();
	void EndScene();
	int32_t CreateBuffer(void* data, int32_t size);
	bool DestoryBuffer(int32_t identity);
	void SetVertex(int32_t identity);
	void Draw();
	//////////////////////////////////////////////////////////////////////////
	void OnSize(int32_t width, int32_t height);
protected:
private:
};