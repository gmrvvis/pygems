/**
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

#ifndef __PYGEMS_TRACINGNODE__
#define __PYGEMS_TRACINGNODE__

#include <pygems/api.h>

#include <vector>

namespace pygems {

    class Point3D
    {

    public:

        PYGEMS_API
        Point3D( float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f )
            : x( x_ ), y( y_ ), z( z_ ) { }

        float x, y, z;

    };

    class TracingNode
    {

    public:

        PYGEMS_API
        TracingNode ( int id_ = 0, float radius_ = 0.0f,
                Point3D position_ = Point3D( )): id( id_ ),
                radius( radius_ ), position( position_ ) { }

        PYGEMS_API
        bool operator==( const TracingNode& node_ )
        {
            return ( this->id == node_.id ) && ( this->radius == node_.radius )
                && ( this->position.x == node_.position.x )
                && ( this->position.y == node_.position.y )
                && ( this->position.z == node_.position.z );

        }

        int id;
        float radius;
        Point3D position;

    };

    typedef std::vector< TracingNode > TracingNodes;
}

#endif //__PYGEMS_TRACINGNODE__
