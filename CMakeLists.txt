cmake_minimum_required (VERSION 3.2)
project (PyGEmSProject)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC ")
set(CMAKE_AUTORCC ON)

add_subdirectory( PyGEmS )
add_subdirectory( examples )
