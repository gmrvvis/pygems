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

#ifndef __PYGEMS_STRATEGYPARAMSBASE__
#define __PYGEMS_STRATEGYPARAMSBASE__

#include "Enums.h"
#include <boost/python.hpp>

namespace NSPyGEmS
{
  namespace bp = boost::python;

  struct StrategyParamsBase
  {
    std::string stringParam = "Description";

    bool operator==( const StrategyParamsBase& );
  };

  struct Point3D
  {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
  };

  struct TracingNode
  {
    int id = 0;
    int parent = 0;
    float radius = 0.0;
    NodeType type = NodeType::REGULAR;
    Point3D position;
  };
}

#endif //__PYGEMS_STRATEGYPARAMSBASE__
