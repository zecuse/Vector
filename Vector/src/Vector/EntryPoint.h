#pragma once

#ifdef VC_PLATFORM_WINDOWS

	extern Vector::Engine* Vector::CreateApplication();

	int main(int argc, char** argv)
	{
		Vector::Log::Init();
		VC_CORE_WARN("Initialized!");

		auto app = Vector::CreateApplication();
		app->Run();
		delete app;

		return 0;
	}

#endif