#pragma once
#include <stdint.h>
#include "IInterface.h"
class IRender :public IInterface
{
public:
	virtual bool Create(int32_t windowId, int32_t width, int32_t height) = 0;
	virtual bool Destory() = 0;
	virtual bool Reset(int32_t width, int32_t height) = 0;
	//Draw
	virtual void BeginScene() = 0;
	virtual void EndScene() = 0;
	//virtual int32_t CreateBuffer(void* data, int32_t size) = 0;
	//virtual bool DestoryBuffer(int32_t identity) = 0;
	//virtual void SetVertex(int32_t identity) = 0;
	virtual void Draw() = 0;
	//////////////////////////////////////////////////////////////////////////
	virtual void OnSize(int32_t width, int32_t height) = 0;
protected:
private:
};