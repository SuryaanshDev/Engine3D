#pragma once

#ifdef ED_PLATFORM_WINDOWS

extern Engine3D::Application* Engine3D::CreateApplication();

int main(int* argc, char** argv) {

	Engine3D::Log::Init();
	ED_CORE_WARN("Initialized Log!");
	int a = 5;
	ED_INFO("Hello! Var = {0}", a);

	auto app = Engine3D::CreateApplication();
	app->Run();
	delete app;
}

#endif