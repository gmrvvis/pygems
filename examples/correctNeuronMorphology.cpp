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

#include <nsol/nsol.h>
#include <pygems/pygems.h>

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
        std::cout << "Usage error: Use: " << argv[0] <<
            "correction_file[.py] morphology_file[.swc]." << std::endl;
        return 1;
    }
    try
    {
        nsol::SwcReader nsolReader;
        auto morphology = nsolReader.readMorphology( std::string( argv[2]));

        auto cManager = pygems::CorrectionManager( std::string( argv[1] ));


        pygems::TracingNodes nodes;
        pygems::TracingNode* newNode;
        int numNeurite = 0;
        int numSection = 0;
        for ( auto neurite: morphology->neurites( ))
        {
            std::cout << "Neurite " << numNeurite << std::endl;
            ++numNeurite;
            numSection = 0;
            for (auto section: neurite->sections())
            {
                std::cout << "    Section " << numSection
                << "\n        In nodes:" << std::endl;
                ++numSection;
                nodes.clear();
                for (auto nsolNode: section->nodes())
                {

                    newNode = new pygems::TracingNode( nsolNode->id( ),
                            nsolNode->radius( ),
                            pygems::Point3D( nsolNode->point( ).x( ),
                                    nsolNode->point( ).y( ),
                                    nsolNode->point( ).z( )));
                    nodes.push_back( *newNode );
                    print( *newNode, std::string( "            " ));
                }
                auto outNodes = cManager.correct( nodes );
                std::cout << "        Out nodes:" << std::endl;
                for ( auto node: outNodes )
                {
                    print( node, std::string( "            " ));
                }

            }
        }
    }

    catch( const bp::error_already_set& )
    {
        std::cerr << "Python execution error: " << std::endl;
        auto errMessage = pygems::CorrectionManager::pyErrorMessage( );
        std::cout << errMessage << std::endl;
        return 1;
    }
}
