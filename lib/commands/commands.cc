#include "commands.hpp"
#include "logger.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

namespace cli {

int run_hello() {
  cli::debug_log("running hello world function!");
  return 0;
}
} // namespace cli
