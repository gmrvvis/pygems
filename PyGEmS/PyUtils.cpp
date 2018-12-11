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

#ifndef __PYGEMS_UTILS__
#define __PYGEMS_UTILS__

#include "PyUtils.h"

#include <iostream>
#include <boost/python.hpp>

namespace NSPyGEmS
{
  namespace bp = boost::python;

  //Extracted from BP Wiki
  bp::object myImportModule( const std::string& module, const std::string& path,
                             bp::object& globals )
  {
    bp::dict locals;
    locals["module_name"] = module;
    locals["path"] = path;

    std::cout << module << std::endl;
    std::cout << path << std::endl;

    bp::exec( "import imp\n"
              "import sys\n"
              "new_module = imp.load_module(module_name, open(path), path, ('py', 'U', imp.PY_SOURCE))\n",
              globals,
              locals );

    std::cout << "---------------" << std::endl;
    return locals["new_module"];
  }

  std::ostream& operator<<( std::ostream& os, const bp::object& o )
  {
    return os << bp::extract < std::string >( bp::str( o ))( );
  }
}

#endif //
