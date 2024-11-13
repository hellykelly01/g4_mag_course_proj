cmake_minimum_required(VERSION 3.16)

project(ScintDet VERSION 1.0.0)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/ToolBox.cmake)

set(CMAKE_BUILD_TYPE Debug)

multi_option(POLYGON_TYPE "polygon type to use for PM" dodecahedron icosahedron)

add_subdirectory(SensitiveDetector)
add_subdirectory(DetectorConstruction)
add_subdirectory(UserActions)
add_subdirectory(ActionInitialization)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE ${Geant4_LIBRARIES} sens_det det_constr user_actions action_init)

install(EXPORT ScintDetTargets
  FILE
    ScintDetTargets.cmake
  NAMESPACE
    ScintDet::
  DESTINATION
    ${CMAKE_INSTALL_PREFIX}/lib/cmake
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  "ScintDet-config-version.cmake"
  COMPATIBILITY SameMajorVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/ScintDet-config-version.cmake"
  cmake/ScintDetConfig.cmake
  DESTINATION 
    ${CMAKE_INSTALL_PREFIX}/lib/cmake
)




