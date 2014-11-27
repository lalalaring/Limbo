
#include "../pch.h"
#include "../Interface/ISound.h"
class NullSound:public ISound
{
public:
	void Create();
	void Destory();
protected:
private:
};