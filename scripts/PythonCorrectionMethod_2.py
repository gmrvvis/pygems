from CorrectionFramework import *

class CorrectionMethod( ):

  def correct(self):

    global inNodes
    global outNodes

    for i in range( 0, len(inNodes), 2 ):
      outNodes.append( inNodes[i] )
