# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\coinFlip_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\coinFlip_autogen.dir\\ParseCache.txt"
  "coinFlip_autogen"
  )
endif()
