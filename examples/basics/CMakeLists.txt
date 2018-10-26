
set(TESTPYGEMSBASIC_SOURCES basic.cpp)
set(TESTPYGEMSBASIC_LINK_LIBRARIES
  PyGEmS
  PyGEmSManager
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
common_application(testPyGEmSBasic NOHELP)

set(TESTPYGEMSTRACINGS_SOURCES tracings.cpp)
set(TESTPYGEMSTRACINGS_LINK_LIBRARIES
  PyGEmS
  PyGEmSManager
  nsol
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
common_application(testPyGEmSTracings NOHELP)
