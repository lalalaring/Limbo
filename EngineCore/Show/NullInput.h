#include "../pch.h"
#include "../Interface/IInput.h"

class NullInput:public IInput
{
public:
	void Create();
	void Destory();

	int GetKeyState(int  Key);
protected:
private:
};