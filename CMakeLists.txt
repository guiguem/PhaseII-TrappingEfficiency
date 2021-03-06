# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required (VERSION 3.1)

#########
# setup #
#########

cmake_policy( SET CMP0048 NEW ) # version in project()
project( Sensitivity VERSION 0.0.1 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scarab/cmake)

include( PackageBuilder )
pbuilder_prepare_project()

########################
# dependencies #
########################

########
# Scarab
########

pbuilder_add_submodule( Scarab Scarab/library )

######
# ROOT
######

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS fftw3 MathCore RIO Hist Tree Net TreePlayer)
#include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

######
# FFTW
######

find_package(FFTW REQUIRED)
if (NOT FFTW_THREADS_FOUND)
  message(FATAL "FFTW_THREADS not found")
endif (NOT FFTW_THREADS_FOUND)
    pbuilder_add_ext_libraries (${FFTW_LIBRARIES})
    set (FFTW_NTHREADS 1 CACHE STRING "Number of threads to use for FFTW processes")
    add_definitions (-DFFTW_NTHREADS=${FFTW_NTHREADS})
    message (STATUS "FFTW configured to use up to ${FFTW_NTHREADS} threads.")
message (STATUS "FFTW_LIBRARIES is ${FFTW_LIBRARIES}")
include_directories (${FFTW_INCLUDE_DIR})
message (STATUS "FFTW_LIBRARIES is ${FFTW_LIBRARIES}")

#############
# Sensitivity
#############

# subdirectories
include_directories (BEFORE 
    ${PROJECT_SOURCE_DIR}/src/MagneticField
    ${PROJECT_SOURCE_DIR}/src/Toolbox
    ${PROJECT_SOURCE_DIR}/src/Trapping
    ${PROJECT_SOURCE_DIR}/src/exe
)
add_subdirectory (src/MagneticField)
add_subdirectory (src/Toolbox)
add_subdirectory (src/Trapping)
add_subdirectory (src/exe)

#######################
# installation config #
#######################

pbuilder_install_config_files()
pbuilder_variables_for_parent()


