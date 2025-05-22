#pragma once
#include "Core.h"

namespace Engine3D {

	class Engine3D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in the CLIENT.
	Application* CreateApplication();
}

