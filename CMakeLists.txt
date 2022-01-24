cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION True)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options("-Wall" "-Wno-switch")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/W4")
endif()

project(SpellChecker VERSION 1.0)

file(GLOB SpellChecker_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SpellChecker)

add_executable(SpellChecker ${SpellChecker_SRC})



