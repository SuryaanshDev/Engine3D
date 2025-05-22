#pragma once

#ifdef ED_PLATFORM_WINDOWS
	#ifdef ED_BUILD_DLL
		#define Engine3D_API __declspec(dllexport)
	#else
		#define Engine3D_API __declspec(dllimport)
	#endif
#else
	#error Engine3D only supports windows!
#endif