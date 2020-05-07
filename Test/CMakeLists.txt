cmake_minimum_required(VERSION 3.5)

project(Lab_1_Test)
#set (CMAKE_C_STANDARD 11)

include_directories(headers)

add_executable(Test 
	Test.c 
	MyString.c
)


