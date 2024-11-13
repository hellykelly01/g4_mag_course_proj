cmake_minimum_required(VERSION 3.20)
project(electron)

set(CMAKE_BUILD_TYPE Debug)

find_package(Geant4 REQUIRED)
find_package(ScintDet REQUIRED)

add_executable(uniform_generation uniform_generation_main.cpp)
add_executable(along_x_generation along_x_generation_main.cpp)
add_executable(along_y_generation along_y_generation_main.cpp)
add_executable(along_z_generation along_z_generation_main.cpp)


target_link_libraries(uniform_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(along_x_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(along_y_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(along_z_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)