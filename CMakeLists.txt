cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(pugstd
    VERSION 0.1.0
    DESCRIPTION "STD library implementation for homebrew projects"
    HOMEPAGE_URL "https://github.com/Pugemon/pugstd"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

set(PLATFORM_DIR "other")
if (VITA)
  set(PLATFORM_DIR "psv")
elseif (SWITCH)
  set(PLATFORM_DIR "nx")
elseif (3DS)
  set(PLATFORM_DIR "3ds")
elseif (WIN32)
  set(PLATFORM_DIR "windows")
endif()

# ---- Declare library ----

add_library(pugstd_pugstd
        source/pugstd.cpp
        source/pugstd/parallel/mutex.cpp
        source/pugstd/parallel/${PLATFORM_DIR}/mutex.cpp
)
add_library(pugstd::pugstd ALIAS pugstd_pugstd)

include(GenerateExportHeader)
generate_export_header(pugstd_pugstd
    BASE_NAME pugstd
    EXPORT_FILE_NAME export/pugstd/pugstd_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(pugstd_pugstd PUBLIC PUGSTD_STATIC_DEFINE)
endif()

set_target_properties(
    pugstd_pugstd PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME pugstd
    OUTPUT_NAME pugstd
)

target_include_directories(
    pugstd_pugstd ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    pugstd_pugstd SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(pugstd_pugstd PUBLIC cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT pugstd_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of pugstd"
  )
endif()

include(cmake/dev-mode.cmake)
