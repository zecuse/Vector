#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Vector
{
	class VECTOR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define VC_CORE_TRACE(...) ::Vector::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VC_CORE_INFO(...) ::Vector::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VC_CORE_WARN(...) ::Vector::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VC_CORE_ERROR(...) ::Vector::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VC_CORE_CRITICAL(...) ::Vector::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define VC_TRACE(...) ::Vector::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VC_INFO(...) ::Vector::Log::GetClientLogger()->info(__VA_ARGS__)
#define VC_WARN(...) ::Vector::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VC_ERROR(...) ::Vector::Log::GetClientLogger()->error(__VA_ARGS__)
#define VC_CRITICAL(...) ::Vector::Log::GetClientLogger()->critical(__VA_ARGS__)