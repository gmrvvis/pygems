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

#ifndef __PYGEMS_STRATEGYPARAMS__
#define __PYGEMS_STRATEGYPARAMS__

#include "Enums.h"
#include "StrategyParamsBase.h"

namespace NSPyGEmS
{
  struct StrategyParams: StrategyParamsBase
  {
    //Simplification parameters (Eg radius distance, alternative deletion of nodes ...) specific for certain nodes
    //Could determined if some neurites have more importance, or different parameters of simplification
    int intParam = 0;
    double floatParam = 0.0;
    TracingOperation operation = TracingOperation::NONE;

    //Basic node information for the tracing treatement
    TracingNode node;
  };
}

#endif //__PYGEMS_STRATEGYPARAMS__
