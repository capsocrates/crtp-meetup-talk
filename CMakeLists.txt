cmake_minimum_required(VERSION 3.2)

project(CRTP)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(class-extension)
add_subdirectory(concept-enforcement)
add_subdirectory(crtp-insantiation)
add_subdirectory(template-instantiation)
