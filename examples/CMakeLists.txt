
set( PYGEMSCORRECTSECTION_SOURCES correctSection.cpp)
set( PYGEMSCORRECTSECTION_LINK_LIBRARIES
    pygems
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    )
common_application( pygemsCorrectSection NOHELP)


if( nsol_FOUND )
    set( PYGEMSCORRECTNEURONMORPHOLOGY_SOURCES correctNeuronMorphology.cpp)
    set( PYGEMSCORRECTNEURONMORPHOLOGY_LINK_LIBRARIES
        pygems
        nsol
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES}
        )
    common_application( pygemsCorrectNeuronMorphology NOHELP)
endif( )