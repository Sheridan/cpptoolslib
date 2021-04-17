cmake_minimum_required(VERSION 3.12)
project(cpptoolslib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CMAKE_BUILD_TYPE "Build type" Release)

message("Configuring as " ${CMAKE_BUILD_TYPE})
if (CMAKE_BUILD_TYPE STREQUAL Debug)
  set(CMAKE_VERBOSE_MAKEFILE ON)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
  add_definitions(-DCPPTL_DEBUG)
endif (CMAKE_BUILD_TYPE STREQUAL Debug)

set(CPPTL_HEADERS
  src/fs/fs.h
  src/networking/networking.h
  src/shell/shell.h
  src/string/string.h
  src/user/user.h
  )

set(CPPTL_SOURCES
  src/fs/fs.cpp
  src/networking/networking.cpp
  src/shell/shell.cpp
  src/string/string.cpp
  src/user/user.cpp
  )

include_directories(
  src
  src/fs
  src/networking
  src/shell
  src/string
  src/user
  )

add_library(cpptools SHARED ${CPPTL_HEADERS} ${CPPTL_SOURCES})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
  add_executable(test test/test.h test/test.cpp)
  target_link_libraries(test PUBLIC cpptools logger stdc++fs)
endif (CMAKE_BUILD_TYPE STREQUAL Debug)
