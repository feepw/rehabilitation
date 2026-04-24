project(rehabilitation_tests)

include(FetchContent)

if (POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz
  URL_HASH SHA256=65fab701d9829d38cb77c14acdc431d2108bfdbf8979e40eb8ae567edf10b27c
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) # Disable GMock
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TESTING_SOURCE_FILES)
add_executable(rehabilitation_tests)
target_sources(rehabilitation_tests PRIVATE ${TESTING_SOURCE_FILES})
target_include_directories(rehabilitation_tests PRIVATE .)
target_link_libraries(rehabilitation_tests PRIVATE rehabilitation gtest_main)

gtest_discover_tests(rehabilitation_tests)

