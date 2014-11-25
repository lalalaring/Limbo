#include "Engine.h"
namespace Limbo
{
	bool Engine::Create()
	{
		m_system.reset(new System());
		m_input.reset(new Input());
		m_render.reset(new Render());
		m_sound.reset(new Sound());
		return true;
	}
	bool Engine::CallSystemCmd(SystemCmd cmd, int32_t para0, int32_t para1)
	{
		switch (cmd)
		{
		case SystemCmd_OnClose:
			break;
		case SystemCmd_OnMinimized:
			break;
		case SystemCmd_OnMaximized:
			break;
		default:
			break;
		}
		return true;
	}

}