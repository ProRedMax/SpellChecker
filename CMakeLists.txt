cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION True)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options("-Wall" "-Wno-switch")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/W4")
endif()

project(SpellChecker VERSION 1.0)

file(GLOB SpellChecker_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

if(NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

	set(data resources/german.dic)

	foreach(item IN LISTS data)
        	message(STATUS ${item})
        	add_custom_command(
            	OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/bin/$<CONFIG>/${item}"
           		COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/bin/$<CONFIG>/${item}"
            	DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
       		)
    	endforeach()
endif()

add_custom_target(RESOURCES DEPENDS ${data})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SpellChecker)

add_executable(SpellChecker ${SpellChecker_SRC})

set_property(TARGET SpellChecker PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR})

add_dependencies(SpellChecker RESOURCES)






