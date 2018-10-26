/*
 * Copyright (c) 2017 CCS/GMRV/URJC/UPM.
 *
 * Authors: Juan P. Brito <juanpedro.brito@upm.es>
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

#ifndef __PYGEMS_STRATEGYFRAMEWORKBPMODULE__
#define __PYGEMS_STRATEGYFRAMEWORKBPMODULE__

#include <PyGEmS/Container.h>
#include <PyGEmS/Strategy.h>
#include <PyGEmS/PyStrategy.h>
#include <PyGEmS/PyUtils.h>

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace NSPyGEmS;

namespace NSPGManager
{
  //Expose to python
  BOOST_PYTHON_MODULE ( StrFramework )
  {
    bp::enum_<TracingOperation>( "TracingOperation" )
            .value( "NONE", TracingOperation::NONE )
            .value( "SIMPLIFY", TracingOperation::SIMPLIFY )
            .value( "ENHANCE", TracingOperation::ENHANCE )
            .value( "FIX", TracingOperation::FIX );

    bp::enum_<NodeType>( "NodeType" )
            .value( "SOMA", NodeType::SOMA )
            .value( "BIFURCATION", NodeType::BIFURCATION )
            .value( "ENDING", NodeType::ENDING )
            .value( "REGULAR", NodeType::REGULAR );

    bp::class_<Point3D>( "Point3D", bp::no_init )
            .def_readwrite( "X", &Point3D::x )
            .def_readwrite( "Y", &Point3D::y )
            .def_readwrite( "Z", &Point3D::z );

    bp::class_<TracingNode>( "TracingNode", bp::no_init )
            .def_readwrite( "id", &TracingNode::id )
            .def_readwrite( "parent", &TracingNode::parent )
            .def_readwrite( "radius", &TracingNode::radius )
            .def_readwrite( "type", &TracingNode::type )
            .def_readwrite( "position", &TracingNode::position );

    bp::class_<StrategyParamsBase>( "Base", bp::no_init );

    bp::class_ < StrategyParams, bp::bases < StrategyParamsBase >> ("StrategyParams", bp::init<>())
            .def_readwrite( "pyIntParam", &StrategyParams::intParam )
            .def_readwrite( "pyFloatParam", &StrategyParams::floatParam )
            .def_readwrite( "pyStringParam", &StrategyParams::stringParam )
            .def_readwrite( "operation", &StrategyParams::operation )
            .def_readwrite( "node", &StrategyParams::node );

    bp::class_<Container>( "Container" );

    bp::class_<PyStrategy, boost::noncopyable>( "Container", bp::init<Container &>()
    ).def( "sendParamaterToCppApplication", &Strategy::receivingParameterFromPython );

    bp::class_<std::vector<StrategyParams> >( "PyGEmSVec" )
            .def( bp::vector_indexing_suite<std::vector<StrategyParams> >());
  }
}
#endif //
