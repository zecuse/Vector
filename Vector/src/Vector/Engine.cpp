#include "Engine.h"
#include "Log.h"
#include "Vector/Events/ApplicationEvent.h"

namespace Vector
{
	Engine::Engine()
	{

	}

	Engine::~Engine()
	{

	}

	void Engine::Run()
	{
		VC_CORE_INFO("Engine on");
		WindowResizeEvent e(1200, 900);
		VC_TRACE(e);

		while (true);
	}
}