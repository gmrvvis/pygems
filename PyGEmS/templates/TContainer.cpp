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

#include "TContainer.h"

namespace NSPyGEmS
{
  template<class T>
  TContainer<T>::TContainer ( )
  { };

  template<class T>
  TContainer<T>::TContainer ( std::vector<T> &vecIn )
          : _container( vecIn )
  { };

  template<class T>
  void TContainer<T>::setContainer ( std::vector<T> &vecIn )
  {
    _container = vecIn;
  };

  template<class T>
  const std::vector<T> &TContainer<T>::getContainer ( )
  {
    return _container;
  };

  template<class T>
  void TContainer<T>::processContainer ( )
  {
    std::cout << "process container for evaluation ... (call from python)" << std::endl;
  }
}
