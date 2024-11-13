cmake_minimum_required(VERSION 3.20)
project(positron)

set(CMAKE_BUILD_TYPE Debug)

find_package(Geant4 REQUIRED)
find_package(ScintDet REQUIRED)

add_executable(uniform_generation uniform_generation_main.cpp)

target_link_libraries(uniform_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
