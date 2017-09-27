# Install script for directory: /Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/yaml/yaml-cpp

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
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.3.dylib;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.dylib;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib" TYPE SHARED_LIBRARY FILES
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/libyaml-cpp.0.5.3.dylib"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/libyaml-cpp.0.5.dylib"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/libyaml-cpp.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.3.dylib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.dylib"
      "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -add_rpath "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/yaml-cpp/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/include/yaml-cpp" TYPE DIRECTORY FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/Scarab/library/param/codec/yaml/yaml-cpp/include/yaml-cpp/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-config.cmake;/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-config-version.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp" TYPE FILE FILES
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/CMakeFiles/yaml-cpp-config.cmake"
    "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/yaml-cpp-config-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake"
         "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/CMakeFiles/Export/_Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/CMakeFiles/Export/_Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/Scarab/library/param/codec/yaml/yaml-cpp/CMakeFiles/Export/_Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/cmake/yaml-cpp/yaml-cpp-targets-debug.cmake")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/pkgconfig/yaml-cpp.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/pkgconfig" TYPE FILE FILES "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/yaml-cpp.pc")
endif()

