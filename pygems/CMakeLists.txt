set( PYGEMS_PUBLIC_HEADERS
        TracingNode.h
        CorrectionManager.h
    )

set( PYGEMS_HEADERS
        CorrectionMethodBase.h
        CorrectionMethod.h
    )

set( PYGEMS_SOURCES
        CorrectionManager.cpp
    )

set( PYGEMS_LINK_LIBRARIES
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES}
    )

common_library(pygems)
