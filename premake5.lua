workspace "GameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

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
		"%{prj.name}/vendor/spdlog/include"
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
