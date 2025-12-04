# CMakeList.txt : CMake project for breakout, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (breakout "Breakout.cpp" "Breakout.hpp" "Entities.cpp" "Entities.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET breakout PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE raylib_static)