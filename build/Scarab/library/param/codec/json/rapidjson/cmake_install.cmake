# Install script for directory: /Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/json/rapidjson

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "pkgconfig" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/pkgconfig/RapidJSON.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/pkgconfig" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/json/rapidjson/RapidJSON.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "doc" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/share/doc/RapidJSON/readme.md")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/share/doc/RapidJSON" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/json/rapidjson/readme.md")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity/rapidjson")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/Sensitivity" TYPE DIRECTORY FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/json/rapidjson/include/rapidjson")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "examples" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/share/doc/RapidJSON/examples/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/share/doc/RapidJSON/examples" TYPE DIRECTORY FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/json/rapidjson/example/" REGEX "/cmakefiles$" EXCLUDE REGEX "/makefile$" EXCLUDE REGEX "/cmake\\_install\\.cmake$" EXCLUDE)
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/RapidJSON/RapidJSONConfig.cmake;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/RapidJSON/RapidJSONConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/RapidJSON" TYPE FILE FILES
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/json/rapidjson/RapidJSONConfig.cmake"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/json/rapidjson/RapidJSONConfigVersion.cmake"
    )
endif()

