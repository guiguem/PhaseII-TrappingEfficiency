# Install script for directory: /Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library

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
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib" TYPE SHARED_LIBRARY FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/libScarab_Sensitivity.dylib")
  if(EXISTS "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -add_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libScarab_Sensitivity.dylib")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/cancelable.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/concurrent_queue.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/destroyer.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/digital.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/error.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/factory.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/member_variables.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/path.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/scarab_api.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/scarab_version.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/singleton.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/time.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/typename.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/logger.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/configurator.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/global_config.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/param.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/param_codec.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/parsable.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/parser.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/param_json.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/param_yaml.hh;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab/authentication.hh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/Scarab" TYPE FILE FILES
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/cancelable.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/concurrent_queue.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/destroyer.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/digital.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/error.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/factory.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/member_variables.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/path.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/scarab_api.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/scarab_version.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/singleton.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/time.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/utility/typename.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/logger/logger.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/configurator.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/global_config.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/param.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/param_codec.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/parsable.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/parser.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/json/param_json.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/yaml/param_yaml.hh"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/authentication/authentication.hh"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/json/rapidjson/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/utility/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/logger/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/json/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/authentication/cmake_install.cmake")
  include("/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/test/cmake_install.cmake")

endif()

