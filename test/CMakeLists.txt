cmake_minimum_required(VERSION 3.14)

project(pugstdTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(pugstd REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(pugstd_test source/pugstd_test.cpp)
target_link_libraries(pugstd_test PRIVATE pugstd::pugstd)
target_compile_features(pugstd_test PRIVATE cxx_std_20)

add_test(NAME pugstd_test COMMAND pugstd_test)

# ---- End-of-file commands ----

add_folders(Test)
