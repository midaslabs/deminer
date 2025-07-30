cmake_minimum_required(VERSION 3.10)

project(xmrig CXX)

include(FetchContent)

FetchContent_Declare(
  xmrig
  GIT_REPOSITORY https://github.com/xmrig/xmrig.git
  GIT_TAG        v6.17.0
)

FetchContent_GetProperties(xmrig)
if(NOT xmrig_POPULATED)
  FetchContent_Populate(xmrig)
  add_subdirectory(${xmrig_SOURCE_DIR} ${xmrig_BINARY_DIR})
endif()

add_library(
  native-lib
  SHARED
  native-lib.cpp
)

target_link_libraries(
  native-lib
  xmrig
)
