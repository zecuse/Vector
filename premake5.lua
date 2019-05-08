workspace "Vector"
architecture "x64"
configurations
{
	"Debug",
	"Release",
	"Dist"
}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
includeDir = {}
includeDir["glfw"] = "Vector/vendor/glfw/include"
include "Vector/vendor/glfw"

project "Vector"
	location "Vector"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")
	
	pchheader "vcpch.h"
	pchsource "Vector/src/vcpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDir.glfw}"
	}
	
	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"VC_PLATFORM_WINDOWS",
			"VC_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines
		{
			"VC_DEBUG",
			"VC_ENABLE_ASSERTS"
		}
		symbols "On"
	
	filter "configurations:Release"
		defines "VC_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "VC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Vector/vendor/spdlog/include",
		"Vector/src"
	}
	
	links
	{
		"Vector"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"VC_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "VC_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "VC_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "VC_DIST"
		optimize "On"