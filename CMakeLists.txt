cmake_minimum_required (VERSION 3.10)
project (pygems VERSION 0.0.1)
set( pygems_VERSION_ABI 1 )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC ")

if( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" )
 message( FATAL "no in source building allowed." )
endif( )

list( APPEND CMAKE_MODULE_PATH
 ${PROJECT_SOURCE_DIR}/CMake
 ${CMAKE_SOURCE_DIR}/CMake/common )

if( NOT EXISTS ${CMAKE_SOURCE_DIR}/CMake/common/Common.cmake )
 message( FATAL_ERROR "CMake/common missing, run: git submodule update --init")
endif( )

option( PYGEMS_OPTIONALS_AS_REQUIRED
        "Force optional dependencies as required" OFF )

if ( PYGEMS_OPTIONALS_AS_REQUIRED )
    set( PYGEMS_OPTS_FIND_ARGS "REQUIRED" )
else()
    set( PYGEMS_OPTS_FIND_ARGS "" )
endif()


include( GitExternal )

set( PYGEMS_DESCRIPTION "PyGEmS - Python generic embedding system." )
set( PYGEMS_LICENSE LGPL )
set( PYGEMS_MAINTAINER "Juan Pedro Brito <juanpedro.brito@upm.es>" )
set( COMMON_PROJECT_DOMAIN es.gmrv )

include( Common )

#Qt must not be required!
#WAR: nsol uses Qt and the keyword "slots" clashes with Python's
add_definitions(-DQT_NO_KEYWORDS)

common_find_package(Eigen3 SYSTEM REQUIRED)
common_find_package(PythonInterp REQUIRED)
common_find_package(PythonLibs REQUIRED)
common_find_package(Boost REQUIRED COMPONENTS date_time filesystem iostreams
        program_options regex system unit_test_framework
        python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
list(APPEND PYGEMS_DEPENDENT_LIBRARIES Eigen3 ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
common_find_package(nsol ${PYGEMS_OPTS_FIND_ARGS})

common_find_package_post( )

set( PROJECT_INCLUDE_NAME pygems )


# Needed because this var is set by PythonLibs and does
# not follow conventional naming
include_directories ( ${Boost_INCLUDE_DIRS}
                      ${PYTHON_INCLUDE_DIRS})

if ( ${PYTHON_VERSION_MAJOR} EQUAL 3 )
    add_definitions( -DPYGEMS_USE_PYTHON3 )
endif ( )

file( COPY "scripts/PythonCorrectionMethod_0.py"
        "scripts/PythonCorrectionMethod_1.py"
        "scripts/PythonCorrectionMethod_2.py"
        DESTINATION "${CMAKE_BINARY_DIR}/bin" )

add_subdirectory( pygems )
add_subdirectory( examples )

set( DOCS README.md LICENSE.txt )
install(FILES ${DOCS} DESTINATION share/PyGEmS COMPONENT dev)

set(DOXYGEN_MAINPAGE_MD README.md)
set(DOXYGEN_EXTRA_INPUT ${PROJECT_SOURCE_DIR}/README.md)
include(DoxygenRule)

include(CPackConfig)
include(CTest)
