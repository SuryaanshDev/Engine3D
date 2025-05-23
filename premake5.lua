workspace "Engine3D"
	architecture "x64"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine3D"
	location "Engine3D"
	kind "SharedLib"
	language "C++" 
	buildoptions {"/utf-8"}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines {

		"ED_PLATFORM_WINDOWS",
		"ED_BUILD_DLL"
	}
	
	postbuildcommands {

		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "ED_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ED_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ED_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions {"/utf-8"}

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"Engine3D/vendor/spdlog/include",
		"Engine3D/src"
	}

	links {

		"Engine3D"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines {

		"ED_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "ED_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ED_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ED_DIST"
		optimize "On"