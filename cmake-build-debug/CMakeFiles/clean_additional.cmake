# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\musicApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\musicApp_autogen.dir\\ParseCache.txt"
  "musicApp_autogen"
  )
endif()
