include(CMakeFindDependencyMacro)

find_dependency(Geant4 REQUIRED)

get_filename_component(SELF_DIR ${CMAKE_CURRENT_LIST_DIR} PATH)

include(${SELF_DIR}/cmake/ScintDetTargets.cmake)