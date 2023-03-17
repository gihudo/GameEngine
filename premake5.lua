workspace "GameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"
	
project "GLFW"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Omurice/vendor/GLFW/include/GLFW/glfw3.h",
		"Omurice/vendor/GLFW/include/GLFW/glfw3native.h",
		"Omurice/vendor/GLFW/src/glfw_config.h",
		"Omurice/vendor/GLFW/src/context.c",
		"Omurice/vendor/GLFW/src/init.c",
		"Omurice/vendor/GLFW/src/input.c",
		"Omurice/vendor/GLFW/src/monitor.c",
		"Omurice/vendor/GLFW/src/vulkan.c",
		"Omurice/vendor/GLFW/src/window.c",
		"Omurice/vendor/GLFW/src/platform.c",
		"Omurice/vendor/GLFW/src/null_init.c",
		"Omurice/vendor/GLFW/src/null_monitor.c",
		"Omurice/vendor/GLFW/src/null_window.c",
		"Omurice/vendor/GLFW/src/null_joystick.c"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"Omurice/vendor/GLFW/src/win32_init.c",
			"Omurice/vendor/GLFW/src/win32_joystick.c",
			"Omurice/vendor/GLFW/src/win32_monitor.c",
			"Omurice/vendor/GLFW/src/win32_time.c",
			"Omurice/vendor/GLFW/src/win32_thread.c",
			"Omurice/vendor/GLFW/src/win32_window.c",
			"Omurice/vendor/GLFW/src/win32_module.c",
			"Omurice/vendor/GLFW/src/wgl_context.c",
			"Omurice/vendor/GLFW/src/egl_context.c",
			"Omurice/vendor/GLFW/src/osmesa_context.c"
		}

		defines
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

project "Omurice"
	location "Omurice"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "ompch.h"
	pchsource "Omurice/src/ompch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/GLFW/include"
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
			"OM_PLATFORM_WINDOWS",
			"OM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}-%{cfg.system}/App")
		}

	filter "configurations:Debug"
		defines "OM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OM_DIST"
		optimize "On"

project "App"
	location "App"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Omurice/vendor/spdlog/include",
		"Omurice/src"
	}

	links
	{
		"Omurice"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		 
	defines
	{
		"OM_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "OM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OM_DIST"
		optimize "On"