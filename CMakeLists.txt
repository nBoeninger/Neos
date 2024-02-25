cmake_minimum_required(VERSION 3.15)

set(This Neos)

project(${This} VERSION 0.0.0)

# GoogleTest Framework
# Conditions for Framework
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE)

add_subdirectory(libraries/googletest)
add_subdirectory(app)
add_subdirectory(neos)
