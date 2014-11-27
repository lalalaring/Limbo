#include "DllExport.h"
extern "C" DLLAPI IInputFactory* Create()
{
	return (IInputFactory*)new DInputFactory();
}

extern "C" DLLAPI int GetType(){ return 4; }