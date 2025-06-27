set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cc")
add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} "LibLogger" "LibCommand" "LibCli")

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${EXECUTABLE_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()
if(ENABLE_DEBUG_SYMBOLS)
  target_set_debug_symbols(
    TARGET ${EXECUTABLE_NAME}
  )
endif()

install(TARGETS ${EXECUTABLE_NAME}
        RUNTIME DESTINATION bin)

