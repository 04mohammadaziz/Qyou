# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mainapplication_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mainapplication_autogen.dir\\ParseCache.txt"
  "mainapplication_autogen"
  )
endif()
