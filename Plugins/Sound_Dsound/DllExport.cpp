#include "DllExport.h"
extern "C" DLLAPI ISoundFactory* Create()
{
	return (ISoundFactory*)new DSoundFactory();
}

extern "C" DLLAPI int GetType(){ return 1; }