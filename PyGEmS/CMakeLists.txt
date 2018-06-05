cmake_minimum_required (VERSION 3.2)
project (PyGEmS)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC ")

mark_as_advanced(CMAKE_BUILD_TYPE)

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)

if (${PYTHON_VERSION_MAJOR} EQUAL 3)
    FIND_PACKAGE(Boost COMPONENTS python3)
else()
    FIND_PACKAGE(Boost COMPONENTS python)
endif()

INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

#Code and headers
file (GLOB PyGEmS_src "*.cpp" "*.hpp")
file (GLOB PyGEmS_h "*.h")

include_directories(  ${CMAKE_CURRENT_BINARY_DIR}
                      ${CMAKE_CURRENT_SOURCE_DIR}  )

#Construccion de la librería
add_library (PyGEmS SHARED 
    ${PyGEmS_src}
    ${PyGEmS_h}
)

LINK_LIBRARIES(${Boost_LIBRARIES} ${PYTHON_LIBRARIES}) # Deprecated but so convenient!

set_target_properties( PyGEmS
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
