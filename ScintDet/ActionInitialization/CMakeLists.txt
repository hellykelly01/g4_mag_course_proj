file(GLOB action_init_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(action_init SHARED ${action_init_sources})

target_include_directories(action_init PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                              $<INSTALL_INTERFACE:include/ActionInitialization/>)

target_link_libraries(action_init PRIVATE ${Geant4_LIBRARIES})

install(TARGETS action_init EXPORT ScintDetTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin

)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/ActionInitialization/
)