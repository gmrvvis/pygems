from CorrectionFramework import *

class CorrectionMethod( ):

  def correct(self):

    global inNodes
    global outNodes

    for i in range( 0, len(inNodes)):
      newNode = TracingNode()
      inNode = inNodes[i]
      newNode.id = inNode.id
      newNode.radius = inNode.radius
      newNode.position.x = inNode.position.x
      newNode.position.y = inNode.position.y
      newNode.position.z = inNode.position.z
      outNodes.append( newNode )

    # Equivalent to
    # outNodes = inNodes;
