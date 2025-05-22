#pragma once

#ifdef ED_PLATFORM_WINDOWS

extern Engine3D::Application* Engine3D::CreateApplication();

int main(int* argc, char** argv) {

	auto app = Engine3D::CreateApplication();
	app->Run();
	delete app;
}

#endif