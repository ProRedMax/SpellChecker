cmake_minimum_required(VERSION 3.12)

project(SpellChecker VERSION 1.0)

file(GLOB SpellChecker_SRC CONFIGURE_DEPENDS "src/*.h", "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(SpellChecker ${SpellChecker_SRC})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)