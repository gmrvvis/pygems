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

#include "Strategy.h"

namespace NSPyGEmS
{
  Strategy::Strategy ( Container &container )
          : _container( container )
  { }

  //Strategy::Strategy ( ) { _container = nullptr; }

  const Container &Strategy::getContainer ( )
  {
    return _container;
  };

  //Method for ping-pong parameters test: Python call CPP, makes some processing and then CPP call Python again!
  void Strategy::receivingParameterFromPython ( float receivedValue )
  {
    std::cout << "CPP method called from Python Value: " << receivedValue << std::endl;

    unsigned int parameterToSend = receivedValue * 2;
    std::cout << "Calling python from CPP Value: " << parameterToSend << std::endl;

    this->sendPartameterToPython( parameterToSend );
  }
}
