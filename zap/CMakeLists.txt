cmake_minimum_required(VERSION 3.5)

add_subdirectory("raylib")

project ("zap")
set(CMAKE_CXX_STANDARD 23)
file(GLOB_RECURSE SRC_FILES
    "src/*.cpp"
    "src/*.hpp"
)
add_library(zap STATIC ${SRC_FILES})

# Make the headers in zap/src available to consumers as plain "Zap.hpp"
target_include_directories(zap
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)



target_link_libraries(zap PUBLIC raylib_static)