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

#ifndef __PYGEMS_MANAGER__
#define __PYGEMS_MANAGER__

#include <PyGEmS/PyUtils.h>

using namespace NSPyGEmS;

namespace NSPGManager
{
  class PyGEmSManager
  {
      bp::object _main;
      bp::object _nameSpace;
      bp::object _module;

    public:

      PyGEmSManager(
#ifdef PYGEMS_USE_PYTHON3
          const std::string&, PyObject* (* initfunc)( void )
#else
          const std::string &, void ( *initfunc ) ( void )   //Python 2.7
#endif
          , const std::string&, const std::string& );

      ~PyGEmSManager( );

      bp::object getModule( );

      bp::object getNamespace( );

      bp::object getModuleAttrib( const std::string& );

      bp::list extractListFromModule( const std::string& );

      void injectValue( const std::string& );

      template< typename T >
      T extractObjectFromList( T, bp::list& list, unsigned int pos );
  };
}

#endif //__PYGEMS_MANAGER__
