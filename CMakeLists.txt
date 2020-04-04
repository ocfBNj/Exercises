cmake_minimum_required(VERSION 3.0)

project(Exercises)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(luogu)

# add_subdirectory(qiniu)

add_subdirectory(template)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
