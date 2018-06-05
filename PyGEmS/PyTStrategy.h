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

#ifndef __PYGEMS_PYTSTRATEGY__
#define __PYGEMS_PYTSTRATEGY__

#include <boost/python.hpp>
#include "TStrategy.h"

namespace NSPyGEmS
{
  namespace bp = boost::python;

  template<typename T>
  class PyTStrategy final : public TStrategy<StrategyParams>, public bp::wrapper<TStrategy<StrategyParams>>

//  class PyTStrategy final:public TStrategy<T>
//                        ,public bp::wrapper<TStrategy<T>>
  {
    using TStrategy<T>::TStrategy;

    void simplify ( ) override
    {
      get_override( "simplify" )();
    }

    void enhance ( ) override
    {
      get_override( "enhance" )();
    }

    void fix ( ) override
    {
      get_override( "fix" )();
    }

    void eval ( ) override
    {
      get_override( "eval" )();
    }

    void sendPartameterToPython ( float params ) override
    {
      get_override( "setContainerResizeDimension" )( params );
    }
  };
}
#endif //
