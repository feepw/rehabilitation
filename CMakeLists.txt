cmake_minimum_required(VERSION 3.21)

project(rehabilitation VERSION 0.0.0 LANGUAGES CXX)

if (PROJECT_IS_TOP_LEVEL)
  option(BUILD_TESTING "Build tests" ON)
else()
  option(BUILD_TESTING "Build tests" OFF)
endif()

add_library(rehabilitation INTERFACE)
target_include_directories(rehabilitation
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(rehabilitation
  INTERFACE
    FILE_SET public_headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
      include/rehabilitation/fibonacci.h
)
target_compile_features(rehabilitation INTERFACE cxx_std_14)

if (BUILD_TESTING)
  include(CTest)
  add_subdirectory(tests)
endif()

