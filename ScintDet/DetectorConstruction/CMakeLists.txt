file(GLOB det_constr_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(det_constr SHARED ${det_constr_sources})

target_include_directories(det_constr PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                             $<INSTALL_INTERFACE:include/DetectorConstruction/>)

target_link_libraries(det_constr PRIVATE sens_det ${Geant4_LIBRARIES})

if (${POLYGON_TYPE} STREQUAL "dodecahedron")
  target_compile_definitions(det_constr PRIVATE "USE_DODECAHEDRON")
endif()

if (${POLYGON_TYPE} STREQUAL "icosahedron")
  target_compile_definitions(det_constr PRIVATE "USE_ICOSAHEDRON")
endif()

install(TARGETS det_constr EXPORT ScintDetTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin

)

install (
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/DetectorConstruction/
)