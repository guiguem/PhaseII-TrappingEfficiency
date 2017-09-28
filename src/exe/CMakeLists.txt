# Main
add_executable(Main main.cxx)
target_link_libraries(Main MagneticField TrappingEfficiency)
add_custom_command(TARGET Main
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Main> ${PROJECT_SOURCE_DIR}/bin/Main)