cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# Use add_subdirectory() to add MathFunctions to this project
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)

# Use target_link_libraries to link the library to our executable
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# Add MathFunctions to Tutorial's target_include_directories()

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
