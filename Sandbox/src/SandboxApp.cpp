#include <Engine3D.h>

class Sandbox : public Engine3D::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Engine3D::Application* Engine3D::	CreateApplication() {

	return new Sandbox();
} 