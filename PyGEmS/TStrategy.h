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

#ifndef __PYGEMS_TSTRATEGY__
#define __PYGEMS_TSTRATEGY__

#include "StrategyParams.h"
#include "TContainer.h"

namespace NSPyGEmS
{
  template<class T>
  class TStrategy : public TContainer<T>
  {
  public:

    TStrategy ( );

    TStrategy ( const std::vector<T> & );

    virtual ~TStrategy ( ) = default;

    virtual void simplify ( ) = 0;

    virtual void enhance ( ) = 0;

    virtual void fix ( ) = 0;

    virtual void eval ( ) = 0;

    virtual void sendPartameterToPython ( float ) = 0;

    void receivingParameterFromPython ( float );
  };
}

#endif //
