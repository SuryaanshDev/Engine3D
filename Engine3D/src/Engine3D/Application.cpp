#include "Application.h"
#include "Engine3D/Events/ApplicationEvent.h"
#include "Engine3D/Log.h"

namespace Engine3D {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication)) {

			ED_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {

			ED_TRACE(e);
		}
		while (true);
	}
}