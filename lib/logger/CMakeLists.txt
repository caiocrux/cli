set(LIB_LOG_NAME "LibLogger")
set(LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/logger.cc")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/logger.hpp")
set(LIBRARY_INCLUDES "./")

add_library(${LIB_LOG_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_LOG_NAME}  PUBLIC ${LIBRARY_INCLUDES} )
target_link_libraries(${LIB_LOG_NAME} PUBLIC spdlog::spdlog)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${LIB_LOG_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(ENABLE_DEBUG_SYMBOLS)
  target_set_debug_symbols(
      TARGET ${LIB_LOG_NAME}
  )
endif()

