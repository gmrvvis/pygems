include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR})

set(PYGEMS_PUBLIC_HEADERS
  Container.h
  Enums.h
  PyStrategy.h
  Strategy.h
  StrategyParamsBase.h
  StrategyParams.h
  PyUtils.h

#Preparing templating!
#Templating
#  PyTStrategy.h
#  TContainer.h
#  TStrategy.h
#  TStrategyFrameworkBPModule.hpp

#  PyGEmSManager.h
#  StrategyFrameworkBPModule.h
  )

set(PYGEMS_HEADERS
  )

set(PYGEMS_SOURCES
  Container.cpp
  Strategy.cpp
  StrategyParamsBase.cpp
  StrategyParams.cpp
  PyUtils.cpp

#Templating
#  TContainer.cpp
#  TStrategy.cpp

#  PyGEmSManager.cpp
#  StrategyFrameworkBPModule.cpp
  )
set(PYGEMS_LINK_LIBRARIES
    nsol
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    )
common_library(PyGEmS)
