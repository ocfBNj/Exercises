cmake_minimum_required(VERSION 3.0)

project(Exercises)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC)
    add_compile_options(/wd4819)
    message("\n\n使用MSVC编译器\n\n")
endif(MSVC)

add_subdirectory(luogu)

# add_subdirectory(qiniu)

add_subdirectory(template)

add_subdirectory(temp)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
