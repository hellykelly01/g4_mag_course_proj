cmake_minimum_required(VERSION 3.20)
project(neutron)

set(CMAKE_BUILD_TYPE Debug)

find_package(Geant4 REQUIRED)
find_package(ScintDet REQUIRED)

add_executable(lifespan lifespan.cpp)
add_executable(uniform_generation uniform_generation_main.cpp)
add_executable(along_x_generation along_x_generation_main.cpp)
add_executable(center_generation center_generation_main.cpp)
add_executable(gamma_energy gamma_energy_main.cpp)

target_link_libraries(lifespan PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(uniform_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(along_x_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(center_generation PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)
target_link_libraries(gamma_energy PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)


