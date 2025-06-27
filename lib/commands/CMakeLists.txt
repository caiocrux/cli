set(LIB_COMMAND_NAME "LibCommand")
set(LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/commands.cc")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/commands.hpp")
set(LIBRARY_INCLUDES "./")

add_library(${LIB_COMMAND_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIB_COMMAND_NAME}  PUBLIC ${LIBRARY_INCLUDES} )
target_link_libraries(${LIB_COMMAND_NAME} PRIVATE "LibLogger")

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${LIB_COMMAND_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(ENABLE_DEBUG_SYMBOLS)
  target_set_debug_symbols(
      TARGET ${LIB_COMMAND_NAME}
  )
endif()

