Course project on Geant4 modelling of scintillation detector. 

There are 4 components:
- ScintDet
- electron
- positron
- neutron

ScintDet is a library that must be compiled and installed. `POLYGON_TYPE` cmake option can be either `dodecahedron` (default) or `icosahedron`, so to make use of icosahedron configuration library must be recompiled and reinstalled. One needs to provide `CMAKE_INSTALL_PREFIX` for custom installation path. Having installed ScintDet, one can get it with cmake `find_package` command.

Other components (electron, neutron and positron) are just bunches of main programms making use of ScintDet linrary. Also analysis root scripts are provided. Also one may specify `CMakePresits.json` files to make build process simpler.
