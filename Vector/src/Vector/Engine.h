#pragma once

#include "Core.h"
#include "Window.h"

namespace Vector
{
	class VECTOR_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Engine* CreateApplication();
}