#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Vector
{
	class VECTOR_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();
	};

	// To be defined in CLIENT
	Engine* CreateApplication();
}