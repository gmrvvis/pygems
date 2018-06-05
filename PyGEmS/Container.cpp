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

#include <iostream>
#include "Container.h"

namespace NSPyGEmS
{
  void Container::addElement ( StrategyParams &element )
  {
    container.push_back( element );
  }

  void Container::setContainer ( std::vector<StrategyParams> &vecIn )
  {
    container = vecIn;
  }

  const std::vector<StrategyParams> &Container::getContainer ( )
  {
    return container;
  }

  void Container::preProcessContainer ( )
  {
    std::cout << "Preparing container for evaluation ... todo" << std::endl;
  }

  void Container::postProcessContainer ( )
  {
    std::cout << "Postprocessing container ... todo" << std::endl;
  }
}
