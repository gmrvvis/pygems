cmake_minimum_required (VERSION 3.10)
project (PyGEmS VERSION 0.0.2)
set( PyGEmS_VERSION_ABI 1 )

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

include( GitExternal )

set( PYGEMS_DESCRIPTION "PyGEmS - Python generic embedding system." )
set( PYGEMS_LICENSE LGPL )
set( PYGEMS_MAINTAINER "Juan Pedro Brito <juanpedro.brito@upm.es>" )
set( COMMON_PROJECT_DOMAIN es.gmrv )

include( Common )

#Qt must not be required!
#WAR: nsol uses Qt and the keyword "slots" clashes with Python's
add_definitions(-DQT_NO_KEYWORDS)

common_find_package(Qt5Widgets SYSTEM)
common_find_package(Qt5Core SYSTEM)
common_find_package(Qt5Gui SYSTEM)
common_find_package(Eigen3 SYSTEM REQUIRED)
common_find_package(PythonInterp REQUIRED)
common_find_package(PythonLibs REQUIRED)
common_find_package(Boost REQUIRED COMPONENTS date_time filesystem iostreams
        program_options regex system unit_test_framework
        python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
common_find_package(nsol REQUIRED)

list(APPEND PYGEMS_DEPENDENT_LIBRARIES Eigen3 nsol ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})


common_find_package_post( )

# Needed because this var is set by PythonLibs and does
# not follow conventional naming
include_directories ( ${Boost_INCLUDE_DIRS}
                      ${PYTHON_INCLUDE_DIRS})

if ( ${PYTHON_VERSION_MAJOR} EQUAL 3 )
    file( COPY "scripts/Test-Python3.py" "scripts/Strategies-Python3.py"
            DESTINATION "${CMAKE_BINARY_DIR}/bin" )
    add_definitions( -DPYGEMS_USE_PYTHON3 )
else ( )
    file(COPY "scripts/Test-Python2.py" "scripts/Strategies-Python2.py"
            DESTINATION "${CMAKE_BINARY_DIR}/bin")
endif ( )

add_subdirectory( PyGEmS )
add_subdirectory( PyGEmSManager )
add_subdirectory( examples/basics )

#Only if Qt Available
if (Qt5Widgets_FOUND)
  add_subdirectory( examples/qttest )
endif (Qt5Widgets_FOUND)

set( DOCS README.md LICENSE.txt )
install(FILES ${DOCS} DESTINATION share/PyGEmS COMPONENT dev)

set(DOXYGEN_MAINPAGE_MD README.md)
set(DOXYGEN_EXTRA_INPUT ${PROJECT_SOURCE_DIR}/README.md)
include(DoxygenRule)

include(CPackConfig)
include(CTest)
