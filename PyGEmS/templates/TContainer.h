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

#ifndef __PYGEMS_TCONTAINER__
#define __PYGEMS_TCONTAINER__

#include <vector>
#include "StrategyParams.h"

namespace NSPyGEmS
{
  template<class T>
  class TContainer
  {
    std::vector<T> &_container;

  public:

    TContainer ( );

    TContainer ( std::vector<T> & );

    virtual ~TContainer ( ) = default;

    void setContainer ( std::vector<T> & );

    const std::vector<T> &getContainer ( );

    void processContainer ( );
  };
}
#endif //
