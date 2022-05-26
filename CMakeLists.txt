cmake_minimum_required(VERSION 3.5)

project(DiffEquationSolver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp)
file(GLOB HEADES *.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADES})
