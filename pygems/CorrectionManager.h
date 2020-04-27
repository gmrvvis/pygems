/*
 * Copyright (c) 2017-2020 CCS/GMRV/URJC/UPM.
 *
 * Authors: Juan P. Brito <juanpedro.brito@upm.es>
 *          Juan Jose Garcia Cantero <juanjose.garcia@urjc.es>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef __PYGEMS_MANAGER__
#define __PYGEMS_MANAGER__

#include <pygems/api.h>

#include "CorrectionMethod.h"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

namespace pygems
{
    namespace bp = boost::python;

    BOOST_PYTHON_MODULE( CorrectionFramework )
    {
        bp::class_ < Point3D >( "Point3D" )
                .def_readwrite( "x", &Point3D::x )
                .def_readwrite( "y", &Point3D::y )
                .def_readwrite( "z", &Point3D::z );

        bp::class_ < TracingNode >( "TracingNode" )
                .def_readwrite( "id", &TracingNode::id )
                .def_readwrite( "radius", &TracingNode::radius )
                .def_readwrite( "position", &TracingNode::position );

        bp::class_ < TracingNodes >( "TracingNodes" )
                .def( bp::vector_indexing_suite <  TracingNodes >( ));


        bp::class_ < CorrectionMethod, boost::noncopyable>("CorrectionMethodBase");
    }


    class CorrectionManager
    {

    public:

        PYGEMS_API
        CorrectionManager(const std::string& correctionMethodFile_,
                          const std::string& inVarName_ = "inNodes",
                          const std::string& outVarName_ = "outNodes" );

        PYGEMS_API
        ~CorrectionManager( );

        PYGEMS_API
        TracingNodes correct( const TracingNodes& nodes_ );

        PYGEMS_API
        static std::string pyErrorMessage( );

    private:

        bp::object _importModule ( const std::string& module_,
                const std::string& path_, bp::object& globals_ );

        bp::object _main;
        bp::object _globals;
        bp::object _module;
        bp::object _correctionMethod;

        std::string _inVarName;
        std::string _outVarName;

    };
}

#endif //
