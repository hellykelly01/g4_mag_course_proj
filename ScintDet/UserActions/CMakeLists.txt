file(GLOB user_actions_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(user_actions SHARED ${user_actions_sources})

target_include_directories(user_actions PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                               $<INSTALL_INTERFACE:include/UserActions/>)

target_link_libraries(user_actions PRIVATE ${Geant4_LIBRARIES})

install(TARGETS user_actions EXPORT ScintDetTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin

)

install (
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/UserActions/
)