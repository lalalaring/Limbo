
#include "../Base/Singleton.h"
#include "../Interface/IInterface.h"
using namespace Limbo;

enum PluginType
{
	PluginType_Render,
	PluginType_Sound,
	PluginType_IO,
	PluginType_Pipline,
	PluginType_Input
};
class PluginMgr :public Singleton<PluginMgr>
{
public:
	int32_t Load(wchar_t* name);
	IInterface* CreateInstance(PluginType type,int32_t module);
	void Free(int32_t module);
protected:
private:
};