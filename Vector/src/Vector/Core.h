#pragma once

#ifdef VC_PLATFORM_WINDOWS
	#ifdef VC_BUILD_DLL
		#define VECTOR_API __declspec(dllexport)
	#else
		#define VECTOR_API __declspec(dllimport)
	#endif
#else
	#error Vector only supports Windows!
#endif

#ifdef VC_ENABLE_ASSERTS
	#define VC_ASSERT(x, ...) { if(!(x)) { VC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VC_CORE_ASSERT(x, ...) { if(!(x)) { VC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VC_ASSERT(x, ...)
	#define VC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)