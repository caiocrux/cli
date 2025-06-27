#include "logger.hpp"

namespace cli {

void init_logger() {
  auto console = spdlog::stdout_color_mt("console");
  spdlog::set_default_logger(console);
  spdlog::set_level(spdlog::level::debug);
  spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");
}
} // namespace cli
