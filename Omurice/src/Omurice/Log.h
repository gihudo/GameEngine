#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Omurice {
	class OM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log
#define OM_CORE_TRACE(...)  ::Omurice::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OM_CORE_INFO(...)   ::Omurice::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OM_CORE_WARN(...)   ::Omurice::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OM_CORE_ERROR(...)  ::Omurice::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OM_CORE_FATAL(...)  ::Omurice::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log
#define OM_TRACE(...)       ::Omurice::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OM_INFO(...)        ::Omurice::Log::GetClientLogger()->info(__VA_ARGS__)
#define OM_WARN(...)        ::Omurice::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OM_ERROR(...)       ::Omurice::Log::GetClientLogger()->error(__VA_ARGS__)
#define OM_FATAL(...)       ::Omurice::Log::GetClientLogger()->fatal(__VA_ARGS__)