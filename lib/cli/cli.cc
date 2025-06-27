#include "cli.hpp"
#include "commands.hpp"
#include "config.hpp"
#include "logger.hpp"
#include <cxxopts.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

namespace cli {

void print_available_commands() {
  std::cout << R"(

cli-tool — Available Commands:
--------------------------------
  --command hello <args>           Print a hello message
  --help                           Show this help message
  --version                        Show version

Example:
  cli-tool --command hello 
)" << std::endl;
}

int handle_cli(int argc, char *argv[]) {
  try {
    cxxopts::Options options("cli-tool", "Command-Line Tool");

    options.add_options()("h,help", "Show help") // --help or -h
        ("v,version", "Show version")            // --version or -v
        ("c,command",
         "Command to run (e.g., hello)", // --command or -c (requires a string
                                         // value)
         cxxopts::value<std::string>());

    const auto result = options.parse(argc, argv);

    if (result.count("help") != 0U) {
      print_available_commands();
      return 0;
    }

    if (result.count("version") != 0U) {
      cli::debug_log("Welcome to {} v{}\n", project_name, project_version);
      return 0;
    }

    if (result.count("command") == 0U) {
      cli::error_log("No command provided. Try --help.");
      return 1;
    }

    const std::string command = result["command"].as<std::string>();
    const std::vector<std::string> unmatched_args = result.unmatched();

    if (command == "hello") {
      return run_hello();
    } else {
      cli::error_log("Unknown command: {} ", command);
      return 1;
    }
  } catch (const std::exception &ex) {
    cli::error_log("Unexpected error: {}", ex.what());
    return 1;
  }
}
} // namespace cli
