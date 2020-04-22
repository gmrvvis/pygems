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

#include <pygems/pygems.h>

#include <random>

namespace bp = boost::python;

void print( const pygems::TracingNode& node_,
        const std::string& prefix_ = std::string( "    " ))
{
    std::cout << prefix_ << "node: " << node_.id << " radius: " << node_.radius
              << " position: " << node_.position.x << ", " << node_.position.y
              << ", " << node_.position.z << std::endl;
}

int main( int argc, char* argv[] )
{
    if( argc != 3 )
    {
        std::cout << "Usage error: Use " << argv[0] <<
            " correction_file[.py] number_nodes[int]." << std::endl;
        return 1;
    }

    int numNodes = atoi( argv[2] );
    try
    {
        auto cManager = pygems::CorrectionManager( std::string( argv[1] ));

        pygems::TracingNodes nodes((numNodes));
        pygems::TracingNode* newNode;

        std::srand(std::time(0));
        for ( int i = 0; i < numNodes; ++i )
        {
            float radius = ((float)std::rand( ) / RAND_MAX ) * 2.0f;
            newNode = new pygems::TracingNode( i, radius,
                    pygems::Point3D( i*0.1f, i*0.5f, i*1.0f ));
            nodes[i] = *newNode;
        }

        auto outNodes = cManager.correct( nodes );

        std::cout << "In nodes: " << nodes.size( ) << std::endl;
        for ( auto node: nodes )
            print ( node );
        std::cout << "Out nodes: " << outNodes.size( ) << std::endl;
        for ( auto node: outNodes )
            print( node );


        return 0;
    }
    catch( const bp::error_already_set& )
    {
        std::cerr << "Python execution error: " << std::endl;
        PyErr_Print( );
        return 1;
    }
}
