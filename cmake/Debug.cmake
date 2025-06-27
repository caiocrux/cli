function(target_set_debug_symbols)
  set(options)
  set(oneValueArgs TARGET)
  set(multiValueArgs)
  cmake_parse_arguments(TDS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  if(NOT TDS_TARGET)
    message(FATAL_ERROR "target_set_debug_symbols: TARGET is required")
  endif()

  if(NOT ENABLE_DEBUG_SYMBOLS)
    message(STATUS "Debug symbols disabled for: ${TDS_TARGET}")
    return()
  endif()

  message(STATUS "Debug symbols enabled for: ${TDS_TARGET}")

  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # /Zi = debug info for MSVC
    target_compile_options(${TDS_TARGET} PRIVATE /Zi)
    target_link_options(${TDS_TARGET} PRIVATE /DEBUG)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # -g = debug info for GCC/Clang
    target_compile_options(${TDS_TARGET} PRIVATE -g)
  else()
    message(WARNING "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}, cannot set debug symbols")
  endif()
endfunction()

