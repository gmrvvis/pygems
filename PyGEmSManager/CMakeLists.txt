
set(PYGEMSMANAGER_HEADERS PyGEmSManager.h)
set(PYGEMSMANAGER_SOURCES PyGEmSManager.cpp
                        StrategyFrameworkBPModule.h)
set(PYGEMSMANAGER_LINK_LIBRARIES
  PyGEmS
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
common_library(PyGEmSManager NOHELP)

