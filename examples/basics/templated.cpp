#include <iostream>
#include <vector>

#include <TStrategyFrameworkBPModule.h>
#include <PyGEmSManager.h>

using namespace NSPyGEmS;
const unsigned int vecSize            = 10;
std::vector<StrategyParams> glb_vec;
unsigned int numResizedNodesInPython  = 15;

int main ( int argc, char* argv[] )
{
  if ( argc != 2 )
  {
    std::cout<<"This test requieres 1 parameter: NumResizedNodesInPython."<<std::endl;
    return 1;
  }
  else numResizedNodesInPython = atoi( argv[ 1 ] );
  
  try
  {
	  //BPCode
    PyGEmSManager myPyGEmSManager("StrFramework", &initTStrFramework, "Strategies", "Strategies.py");    
    bp::object Strategy   = myPyGEmSManager.getModuleAttrib( "Strategy" );    

    TStrategy<StrategyParams> myTStrategy;
     
    StrategyParams  lStrategyParams;    
    for (int  i=0;i<vecSize;++i) 
    {
      lStrategyParams.stringParam = "MyTest_" + std::to_string(lStrategyParams.intParam) + "_";      
      lStrategyParams.intParam++;
      glb_vec.push_back(lStrategyParams);
    }
    myTStrategy.setContainer ( glb_vec );

    bp::object _strategy  = reinterpret_cast<bp::object>(myTStrategy);
    
    std::cout<<"Initial vector (Showing only string (from base class) parameter)."<<std::endl;
    for (int i=0;i<vecSize;++i) std::cout<<myTStrategy.getContainer()[i].stringParam <<std::endl;
    
    std::string injectedVarName   = "vecIn";
    std::string injectedVarName3  = "listOut";
    
    //BPCode
    myPyGEmSManager.getModule().attr(injectedVarName.c_str())   = myTStrategy.getContainer();
    myPyGEmSManager.getModule().attr(injectedVarName3.c_str())  = 0;

    std::cout <<"Initial vector dimensions. Value:" <<myTStrategy.getContainer().size() <<std::endl;
    
    std::cout <<"Set new dimensions of the vector to python. Value:" <<numResizedNodesInPython <<std::endl;    
    _strategy.attr("setContainerResizeDimension")(numResizedNodesInPython);

    std::cout <<"Calling python methods from CPP."<<std::endl;
    
    _strategy.attr("simplify")();
    _strategy.attr("fix")();
    _strategy.attr("enhance")();

    std::cout <<"Recovering new container from Python."<<std::endl;            
    bp::list result = myPyGEmSManager.extractListFromModule(injectedVarName3.c_str());    

    int n = bp::len(result);
    std::cout <<"Container recovered dimensions Value:" <<n <<std::endl;

    std::cout <<"Showing received string value (modified on python):"<<std::endl;    
    for (int  i=0;i<n;++i) 
    {
        StrategyParams val = bp::extract<StrategyParams>(result[i]);
        std::cout <<val.stringParam <<std::endl;;
    }

    //Ping pong test
    std::cout <<"Starting ping-pong test:"<<std::endl;
    _strategy.attr("eval")();

    std::cout <<std::endl;
    return 0;
  }
  catch ( const bp::error_already_set & )
  {
    std::cerr << ">>> Error! Uncaught exception:\n";
    PyErr_Print();
    return 1;
  }
}
