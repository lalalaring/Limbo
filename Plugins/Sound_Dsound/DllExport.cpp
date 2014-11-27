#include "DllExport.h"
extern "C" DLLAPI ISoundFactory* Create()
{
	return (ISoundFactory*)new DSoundFactory();
}