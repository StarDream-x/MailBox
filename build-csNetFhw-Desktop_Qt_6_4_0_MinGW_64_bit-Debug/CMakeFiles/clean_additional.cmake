# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\csNetFhw_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\csNetFhw_autogen.dir\\ParseCache.txt"
  "csNetFhw_autogen"
  )
endif()
