#include "vcpch.h"
#include "Engine.h"

namespace Vector
{
	Engine::Engine()
		: m_Window(std::unique_ptr<Window>(Window::Create()))
	{

	}

	Engine::~Engine()
	{

	}

	void Engine::Run()
	{
		VC_CORE_INFO("Engine on");
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}