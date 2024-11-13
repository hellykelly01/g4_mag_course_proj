cmake_minimum_required(VERSION 3.20)
project(neutron)

set(CMAKE_BUILD_TYPE Debug)

find_package(Geant4 REQUIRED)
find_package(ScintDet REQUIRED)

add_executable(lifespan lifespan.cpp)

target_link_libraries(lifespan PRIVATE ${Geant4_LIBRARIES} ScintDet::sens_det ScintDet::det_constr ScintDet::user_actions ScintDet::action_init)


