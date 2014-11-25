#include "Engine.h"
//#include <windows.h>
namespace Limbo
{
	bool Engine::Create()
	{
		m_system.reset(new System());
		m_input.reset(new Input());
		m_render.reset(new Render());
		m_sound.reset(new Sound());
		m_system->Create();
		return true;
	}
	bool Engine::Destory()
	{
		m_system->Destory();
		m_system.reset();
		m_input.reset();
		m_render.reset();
		m_sound.reset();
		return true;
	}
	bool Engine::CallSystemCmd(SystemCmd cmd, int32_t para0, int32_t para1)
	{
		switch (cmd)
		{
		case SystemCmd_OnClose:
			//PostQuitMessage(0);
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
	bool Engine::InputHandler(int inputkey)
	{
		int s = inputkey;
		return true;
	}
}