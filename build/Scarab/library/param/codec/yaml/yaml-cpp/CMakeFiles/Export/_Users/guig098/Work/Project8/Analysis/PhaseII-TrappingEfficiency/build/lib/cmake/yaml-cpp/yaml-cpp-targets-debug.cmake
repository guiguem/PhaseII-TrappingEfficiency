#----------------------------------------------------------------
# Generated CMake target import file for configuration "DEBUG".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "yaml-cpp" for configuration "DEBUG"
set_property(TARGET yaml-cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(yaml-cpp PROPERTIES
  IMPORTED_LOCATION_DEBUG "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.3.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libyaml-cpp.0.5.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS yaml-cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_yaml-cpp "/Users/guig098/Work/Project8/Analysis/PhaseII-TrappingEfficiency/build/lib/libyaml-cpp.0.5.3.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
