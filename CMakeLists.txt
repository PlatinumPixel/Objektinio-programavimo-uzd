cmake_minimum_required(VERSION 3.10)
project(ObjektinioProgramavimo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include_directories(${CMAKE_SOURCE_DIR})