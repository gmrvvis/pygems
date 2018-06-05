include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR})

set(PYGEMS_PUBLIC_HEADERS
  Container.h
  Enums.h
  PyGEmSManager.h
  PyStrategy.h
  PyTStrategy.h
  Strategy.h
  StrategyParamsBase.h
  StrategyParams.h
  TContainer.h
  TStrategy.h
  StrategyFrameworkBPModule.hpp
  TStrategyFrameworkBPModule.hpp
  Utils.hpp
  )

set(PYGEMS_HEADERS
  )

set(PYGEMS_SOURCES
  Container.cpp
  PyGEmSManager.cpp
  Strategy.cpp
  StrategyParamsBase.cpp
  StrategyParams.cpp
  TContainer.cpp
  TStrategy.cpp
  )

common_library(PyGEmS)
