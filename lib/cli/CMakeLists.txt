set(LIB_CLI_NAME "LibCli")
set(LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/cli.cc")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/cli.hpp")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIB_CLI_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_CLI_NAME}  PUBLIC ${LIBRARY_INCLUDES} )
target_link_libraries(${LIB_CLI_NAME} PRIVATE "LibLogger" "LibCommand" cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${LIB_CLI_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(ENABLE_DEBUG_SYMBOLS)
  target_set_debug_symbols(
    TARGET ${LIB_CLI_NAME}
  )
endif()

