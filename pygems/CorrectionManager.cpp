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

#include "CorrectionManager.h"

#include <iostream>

namespace pygems
{
    namespace bp = boost::python;


    CorrectionManager::CorrectionManager(
            const std::string& correctionMethodFile_,
            const std::string& inVarName_, const std::string& outVarName_ )
        : _inVarName ( inVarName_)
        , _outVarName ( outVarName_ )
    {
#ifdef PYGEMS_USE_PYTHON3
        PyImport_AppendInittab( "CorrectionFramework", &PyInit_CorrectionFramework );
#else

        PyImport_AppendInittab( "CorrectionFramework", &initCorrectionFramework );
#endif
        Py_Initialize( );

        _main = bp::import( "__main__" );
        _globals = _main.attr( "__dict__" );
        _module = _importModule( "correctionMethod", correctionMethodFile_.c_str( ),
                _globals );

        bp::object CorrectionMethodClass = _module.attr( "CorrectionMethod" );

        _correctionMethod = CorrectionMethodClass(  );
    }

    CorrectionManager::~CorrectionManager( )
    {

    }

    TracingNodes CorrectionManager::correct(const TracingNodes& nodes_ )
    {
        _module.attr( _inVarName.c_str( )) = nodes_;
        _module.attr( _outVarName.c_str( )) = TracingNodes();

        _correctionMethod.attr( "correct" )( );

        TracingNodes outNodes = bp::extract < TracingNodes >(
                _module.attr( _outVarName.c_str( )));
        return outNodes;
    }


    bp::object CorrectionManager::_importModule(const std::string &module_,
                                                const std::string &path_, bp::object &globals_ )
    {
        bp::dict locals;
        locals["module_name"] = module_;
        locals["path"] = path_;

        std::cout << module_ << std::endl;
        std::cout << path_ << std::endl;

        bp::exec( "import imp\n"
                  "import sys\n"
                  "new_module = imp.load_module(module_name, open(path), path, ('py', 'U', imp.PY_SOURCE))\n",
                  globals_, locals );

        std::cout << "Imported module: " << module_ << std::endl;
        return locals["new_module"];
    }

}