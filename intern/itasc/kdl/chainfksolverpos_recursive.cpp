/** \file itasc/kdl/chainfksolverpos_recursive.cpp
 * \ingroup intern_itasc
 */
// Copyright  (C)  2007  Francois Cauwe <francois at cauwe dot org>
// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include "chainfksolverpos_recursive.hpp"
#include <iostream>

namespace KDL {

    ChainFkSolverPos_recursive::ChainFkSolverPos_recursive(const Chain& _chain):
        chain(_chain)
    {
    }

    int ChainFkSolverPos_recursive::JntToCart(const JntArray& q_in, Frame& p_out, int segmentNr)
    {
		unsigned int segNr = (unsigned int)segmentNr;
        if(segmentNr<0)
             segNr=chain.getNrOfSegments();

        p_out = Frame::Identity();

        if(q_in.rows()!=chain.getNrOfJoints())
            return -1;
        else if(segNr>chain.getNrOfSegments())
            return -1;
        else{
            int j=0;
            for(unsigned int i=0;i<segNr;i++){
                p_out = p_out*chain.getSegment(i).pose(((JntArray&)q_in)(j));
				j+=chain.getSegment(i).getJoint().getNDof();
            }
            return 0;
        }
    }


    ChainFkSolverPos_recursive::~ChainFkSolverPos_recursive()
    {
    }


}
