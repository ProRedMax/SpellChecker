cmake_minimum_required(VERSION 3.12)

project(SpellChecker VERSION 1.0)

file(GLOB SpellChecker_SRC CONFIGURE_DEPENDS "src/*.h", "src/*.cpp")

add_executable(SpellChecker ${SpellChecker_SRC})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SpellChecker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)