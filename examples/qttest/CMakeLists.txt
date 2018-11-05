
set(UIDIR ${PROJECT_SOURCE_DIR}/ui)
set(QRCDIR ${PROJECT_SOURCE_DIR}/qrc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

set(QTTEST_HEADERS
  mainwindow.h
)

set(QTTEST_SOURCES 
  mainwindow.cpp
  main.cpp
)

set(QTTEST_LINK_LIBRARIES
  Qt5::Gui
  Qt5::Widgets
  Qt5::Core
  ${Boost_LIBRARIES} 
  ${PYTHON_LIBRARIES}
  PyGEmS
  PyGEmSManager
)

common_application(qttest GUI NOHELP)
