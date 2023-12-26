# ----------------------------------------------------------------------
# Template for CMakeLists.txt
# ----------------------------------------------------------------------
cmake_minimum_required(VERSION 3.10.2)

set(program "myProjectRunFile") # Change myProjectRunFile by the current 
                                # run file. Commas " " required!

project(${program})

#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cc")
add_executable(${program} ${SOURCES})
include_directories(include)
target_link_libraries(${program} m) #link the math library

#----- From Jame's Blog: http://jamesgregson.blogspot.com.es 
# "Putting CMake binaries in a specific directory" ---------------------
set_target_properties( ${program} PROPERTIES
 RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/bin/Debug"
 RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release"
)
# ----------------------------------------------------------------------

# Create the run directory 
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/run)

SET_PROPERTY(TARGET ${program}
	PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/run
)

ADD_CUSTOM_TARGET(run COMMAND ${program}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/run
  COMMENT "Run with ${CMAKE_BUILD_TYPE} configuration"
)

install(TARGETS ${program} DESTINATION $ENV{HOME}/bin)
