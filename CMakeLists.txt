cmake_minimum_required(VERSION 3.12)
project(cpptoolslib)
project(cpptoolslib VERSION 1.0.0)

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

include(GNUInstallDirs)

install(TARGETS cpptools
  EXPORT cpptoolsTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY src/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
)

install(EXPORT cpptoolsTargets
  FILE cpptoolsTargets.cmake
  NAMESPACE cpptools::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  @ONLY
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
