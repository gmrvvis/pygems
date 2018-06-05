# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()  
endif()

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)

if (${PYTHON_VERSION_MAJOR} EQUAL 3)
    FIND_PACKAGE(Boost COMPONENTS python3)
else()
    FIND_PACKAGE(Boost COMPONENTS python)
endif()

include_directories( ../PyGEmS )
INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
add_executable(testPyGEmS_basic
	basic.cpp
)
target_link_libraries(testPyGEmS_basic
	PyGEmS
  ${Boost_LIBRARIES} 
  ${PYTHON_LIBRARIES}
)

include_directories( ../nsol )
INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
add_executable(testPyGEmS_tracings
	tracings.cpp
)
target_link_libraries(testPyGEmS_tracings
	PyGEmS
  nsol
  ${Boost_LIBRARIES} 
  ${PYTHON_LIBRARIES}
)

set_target_properties( testPyGEmS_basic
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set_target_properties( testPyGEmS_tracings
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
