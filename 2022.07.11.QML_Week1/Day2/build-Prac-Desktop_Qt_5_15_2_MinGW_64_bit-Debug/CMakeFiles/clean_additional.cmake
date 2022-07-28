# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Prac_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Prac_autogen.dir\\ParseCache.txt"
  "Prac_autogen"
  )
endif()
