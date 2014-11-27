#include "DSoundFactory.h"
#include "DSoundRender.h"

ISound* DSoundFactory::Create()
{
	return new DSoundRender();
}