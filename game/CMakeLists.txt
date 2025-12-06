# CMakeList.txt : CMake project for breakout, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)
# Add source to this project's executable.
file(GLOB_RECURSE SRC_FILES
    "*.cpp"
    "*.hpp"
)
add_executable (game_cpp "${SRC_FILES}" "main.cpp" "Game.cpp" )


# TODO: Add tests and install targets if needed
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE zap)