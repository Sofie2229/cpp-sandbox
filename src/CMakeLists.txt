cmake_minimum_required(VERSION 3.26)

project("main")

# set(CMAKE_CXX_STANDARD "26")
set(CMAKE_CXX_STANDARD "20")
set(CMAKE_C_STANDARD "11")

file(GLOB_RECURSE SRC_FILES 
	"*.c"
	"*.h"
	"*.cpp"
	"*.hpp"
	"*.cxx"
	"*.hxx"
)

link_libraries(glfw)

add_executable("${PROJECT_NAME}" "${SRC_FILES}")
