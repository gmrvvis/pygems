from CorrectionFramework import *

class CorrectionMethod(  ):

  def correct(self):

    global inNodes
    global outNodes

    outNodes.append( inNodes[0] )

    outNodes.append( inNodes[-1] )