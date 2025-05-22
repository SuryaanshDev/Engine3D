#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine3D {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {

		spdlog::set_pattern("%^[%T] %n: %v%$"); // timestamp || name of the logo || acutal message {message pattern}
		s_CoreLogger = spdlog::stdout_color_mt("Engine3D");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}