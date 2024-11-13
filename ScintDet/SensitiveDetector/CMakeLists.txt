file(GLOB sens_det_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(sens_det SHARED ${sens_det_sources})

target_include_directories(sens_det PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                           $<INSTALL_INTERFACE:include/SensitiveDetector/>)

target_link_libraries(sens_det PRIVATE ${Geant4_LIBRARIES})

install(TARGETS sens_det EXPORT ScintDetTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin

)

install (
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/SensitiveDetector/
)