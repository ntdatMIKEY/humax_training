# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\example3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\example3_autogen.dir\\ParseCache.txt"
  "example3_autogen"
  )
endif()
