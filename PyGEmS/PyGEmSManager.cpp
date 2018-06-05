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

#include "PyGEmSManager.h"

#include <boost/python.hpp>
//#include <boost/filesystem.hpp>

namespace NSPyGEmS
{
  namespace bp = boost::python;

  PyGEmSManager::PyGEmSManager ( const std::string &bpModName, void ( *initfunc ) ( void ) //Python 2.7
          //const std::string & bpModName, PyObject* (*initfunc)(void)  //Python >= 3
          , const std::string &modName, const std::string &modFile )
  {
    Py_Initialize();

//    boost::filesystem::path workingDir = boost::filesystem::absolute("./").normalize();
//    PyObject* sysPath = PySys_GetObject("path");
//    PyList_Insert( sysPath, 0, PyBytes_FromString(workingDir.string().c_str()));

    PyImport_AppendInittab( bpModName.c_str(), initfunc );

    _main = bp::import( "__main__" );
    _nameSpace = _main.attr( "__dict__" );
    _module = importModule( modName.c_str(), modFile.c_str(), _nameSpace );
  }

  PyGEmSManager::~PyGEmSManager ( )
  {
    //De-Init Python!!!
  }

  bp::object PyGEmSManager::getModule ( )
  {
    return _module;
  }

  bp::object PyGEmSManager::getNamespace ( )
  {
    return _nameSpace;
  }

  void PyGEmSManager::injectValue ( const std::string &value )
  {
    _module.attr( value.c_str());
  }

  bp::object PyGEmSManager::getModuleAttrib ( const std::string &attrName )
  {
    return _module.attr( attrName.c_str());
  }

  bp::list PyGEmSManager::extractListFromModule ( const std::string &listName )
  {
    return bp::extract<bp::list>( _module.attr( listName.c_str()));
  }

  template<typename T>
  T PyGEmSManager::extractObjectFromList ( T, bp::list &list, unsigned int pos )
  {
    return bp::extract<T>( list[pos] );
  }
}
