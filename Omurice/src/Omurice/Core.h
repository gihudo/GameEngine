#pragma once

#ifdef OM_PLATFORM_WINDOWS
	#ifdef OM_BUILD_DLL
		#define OM_API __declspec(dllexport)
	#else
		#define OM_API __declspec(dllimport)
	#endif
#else
	#error Omurice only support Windows
#endif 
