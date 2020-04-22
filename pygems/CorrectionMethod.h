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

#ifndef __PYGEMS_CORRECTIONMETHOD__
#define __PYGEMS_CORRECTIONMETHOD__


#include "CorrectionMethodBase.h"
#include <boost/python.hpp>


namespace pygems
{

    namespace bp = boost::python;

    class CorrectionMethod final
            : public CorrectionMethodBase
            , public bp::wrapper < CorrectionMethodBase >
    {

        using CorrectionMethodBase::CorrectionMethodBase;

        void correct( ) override
        {
            get_override("correct")( );
        };

    };
}

#endif //
