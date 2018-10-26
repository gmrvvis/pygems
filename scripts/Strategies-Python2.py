# Copyright (c) 2017 CCS/GMRV/URJC/UPM.
  
# Authors: Juan P. Brito <juanpedro.brito@upm.es>
  
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License version 3.0 as published
# by the Free Software Foundation.
  
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
  
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

from StrFramework import *

class Strategy(Container):

  dims = 0;
  xMedia = 0;
  
  def __init__(self, stlContainer):
    Container.__init__(self, stlContainer)

  def simplify(self):
    print "Py: Running Python code! Simplifiying"

    global originalNodes
    global simplifiedNodes
    displacement = 3
    simplifiedNodes = []

    print "Simplifiying only odd nodes! "
    for i in range (0, len(originalNodes)):
      if i%displacement == 0:
        o = StrategyParams()
        o.pyStringParam = "Id_" + str(originalNodes[i]);
        o.node.position.X = originalNodes[i].node.position.X
        o.node.position.Y = originalNodes[i].node.position.Y
        o.node.position.Z = originalNodes[i].node.position.Z
        o.node.radius = originalNodes[i].node.radius
        o.node.id = originalNodes[i].node.id
        o.node.parent = originalNodes[i].node.parent
        simplifiedNodes.append(o)

    print "Original elements: ", str(len(originalNodes))
    print "New elements: ", str(len(simplifiedNodes))

  def enhance(self):
    print "Py: Running Python code! Enhancing"

    global originalNodes
    global simplifiedNodes
    displacement = 0.5
    originalId = originalNodes[0].node.id
    simplifiedNodes = []

    print "Applying simple midpoint linear enhancing!"
    for i in range (0, len(originalNodes)-1):
      o = StrategyParams()
      o.pyStringParam = "Id_" + str(i+originalId);
      o.node.position.X = originalNodes[i].node.position.X
      o.node.position.Y = originalNodes[i].node.position.Y
      o.node.position.Z = originalNodes[i].node.position.Z
      o.node.radius = originalNodes[i].node.radius
      o.node.id = originalId + originalNodes[i].node.id

      o.node.parent = originalNodes[i].node.parent
      simplifiedNodes.append(o)
      originalId+=1

      o2 = StrategyParams()
      o2.pyStringParam = "Id_" + str(i+originalId);
      o2.node.position.X = (originalNodes[i].node.position.X + originalNodes[i+1].node.position.X)*0.5
      o2.node.position.Y = (originalNodes[i].node.position.Y + originalNodes[i+1].node.position.Y)*0.5
      o2.node.position.Z = (originalNodes[i].node.position.Z + originalNodes[i+1].node.position.Z)*0.5
      o2.node.radius = (originalNodes[i].node.radius + originalNodes[i+1].node.radius)*0.5
      o2.node.id = originalId + originalNodes[i].node.id

      o2.node.parent = originalNodes[i].node.parent
      simplifiedNodes.append(o2)

    #Last node
    simplifiedNodes.append(originalNodes[len(originalNodes)-1])
    print "Original elements: ", str(len(originalNodes))
    print "New elements: ", str(len(simplifiedNodes))
      
  def fix(self):
    print "Py: Running Python code! Fixing -> To be implemented"

  def eval(self):
    print "Py: Running Python code! Evaluation (Used for CPP-Python ping.pong parameter test!)"
    print "Py: Sending XMedia to CPP (calling CPP method) Value: " + str(self.xMedia)
    self.sendParamaterToCppApplication(self.xMedia)

  def setContainerResizeDimension(self, o):
    print "Py: Python method called from CPP - Value: " + str(o)
    self.dims = o
