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
    print "Py: Running Python code! Simplifiying -> To be implemented"  
  
  
  def enhance(self):
    print "Py: Running Python code! Enhancing"
    
    global vecIn
    global listOut
    listOut = []

    i = 0
    for x in range (0, self.dims):
      o = StrategyParams()
      o.pyStringParam = "__Prev" + vecIn[x%len(vecIn)].pyStringParam;
      listOut.append(o)
      listOut[x].pyStringParam = listOut[x].pyStringParam + "_" + str ( int ( i ) )
      listOut[x].node.position.X = i
      self.xMedia = self.xMedia + listOut[x].node.position.X
      i=i+1
      print "Py: Coord X: " + str(listOut[x].node.position.X)
    
    self.xMedia = self.xMedia / self.dims;
      
  def fix(self):
    print "Py: Running Python code! Fixing -> To be implemented"

  def userDefined(self):
    print "Py: Calling user defined method!"
    self.enhance()
    self.simplify()
    self.fix()

  def eval(self):
    print "Py: Running Python code! Evaluation (Used for CPP-Python ping.pong parameter test!)"
    print "Py: Sending XMedia to CPP (calling CPP method) Value: " + str(self.xMedia)
    self.sendParamaterToCppApplication(self.xMedia)

  def setContainerResizeDimension(self, o):
    print "Py: Python method called from CPP - Value: " + str(o)
    self.dims = o
