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