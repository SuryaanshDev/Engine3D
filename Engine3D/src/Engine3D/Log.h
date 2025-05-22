#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Engine3D {
	
	class Engine3D_API Log {

	public:
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log members
#define ED_CORE_TRACE(...)    ::Engine3D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ED_CORE_INFO(...)     ::Engine3D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ED_CORE_WARN(...)     ::Engine3D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ED_CORE_ERROR(...)     ::Engine3D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ED_CORE_FATAL(...)    ::Engine3D::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log members
#define ED_TRACE(...)    ::Engine3D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ED_INFO(...)     ::Engine3D::Log::GetClientLogger()->info(__VA_ARGS__)
#define ED_WARN(...)     ::Engine3D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ED_ERROR(...)     ::Engine3D::Log::GetClientLogger()->error(__VA_ARGS__)
#define ED_FATAL(...)    ::Engine3D::Log::GetClientLogger()->fatal(__VA_ARGS__)