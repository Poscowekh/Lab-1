cmake_minimum_required(VERSION 3.5)

project(Lab 1)
#set (CMAKE_C_STANDARD 11)

add_executable(Main 
	Main.c 
	MyString.c
)

include_directories(headers)

target_link_libraries(1 m)


