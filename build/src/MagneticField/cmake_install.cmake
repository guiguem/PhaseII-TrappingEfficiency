# Install script for directory: /Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/src/MagneticField

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "DEBUG")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib" TYPE SHARED_LIBRARY FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/src/MagneticField/libMagneticField.dylib")
  if(EXISTS "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib"
      -change "@rpath/libScarab_Sensitivity.dylib" "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -add_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libMagneticField.dylib")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/MagneticField.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/src/MagneticField/MagneticField.h")
endif()

