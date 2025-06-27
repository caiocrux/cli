#pragma once
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <string>

namespace cli {
void init_logger();

template <typename... Args>
void debug_log(const std::string &fmt, Args &&...args) {
  spdlog::debug(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void info_log(const std::string &fmt, Args &&...args) {
  spdlog::info(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void warn_log(const std::string &fmt, Args &&...args) {
  spdlog::warn(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void error_log(const std::string &fmt, Args &&...args) {
  spdlog::error(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void critical_log(const std::string &fmt, Args &&...args) {
  spdlog::critical(fmt, std::forward<Args>(args)...);
}

} // namespace cli
