if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/pugstd-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package pugstd)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT pugstd_Development
)

install(
    TARGETS pugstd_pugstd
    EXPORT pugstdTargets
    RUNTIME #
    COMPONENT pugstd_Runtime
    LIBRARY #
    COMPONENT pugstd_Runtime
    NAMELINK_COMPONENT pugstd_Development
    ARCHIVE #
    COMPONENT pugstd_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    pugstd_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE pugstd_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(pugstd_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${pugstd_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT pugstd_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${pugstd_INSTALL_CMAKEDIR}"
    COMPONENT pugstd_Development
)

install(
    EXPORT pugstdTargets
    NAMESPACE pugstd::
    DESTINATION "${pugstd_INSTALL_CMAKEDIR}"
    COMPONENT pugstd_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
