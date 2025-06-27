cmake_minimum_required(VERSION 3.12)

project(CliTool VERSION 0.0.1 LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# FetchContent used to bring in dependencies
include(FetchContent)

# Project/Library Names
set(EXECUTABLE_NAME "cli-tool")

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)
option(ENABLE_DEBUG_SYMBOLS "Enable debug symbols (-g or equivalent)" ON)

# CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if (ENABLE_DEBUG_SYMBOLS)
    include(Debug)
endif()

# nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.2
)
FetchContent_MakeAvailable(json)

# spdlog (logging)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0
)
FetchContent_MakeAvailable(spdlog)

# cxxopts(library for command-line parsing)
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG        v3.1.1
)
FetchContent_MakeAvailable(cxxopts)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(configured)

