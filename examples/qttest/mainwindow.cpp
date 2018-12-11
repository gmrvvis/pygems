#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <PyGEmSManager/StrategyFrameworkBPModule.h>
#include <PyGEmSManager/PyGEmSManager.h>

MainWindow::MainWindow( QWidget* parent )
  : QMainWindow( parent ), ui( new Ui::MainWindow )
{
  ui->setupUi( this );

  QObject::connect( ui->pushButton_testPyGEmS, SIGNAL( clicked( )), this,
                    SLOT( testPyGEmS( )));
}

MainWindow::~MainWindow( )
{
  delete ui;
}

void MainWindow::testPyGEmS( )
{

  try
  {
    NSPGManager::PyGEmSManager* myPyGEmSManager;

#ifdef PYGEMS_USE_PYTHON3
    //Python >=3
    myPyGEmSManager = new NSPGManager::PyGEmSManager( "StrFramework",
                                                      &NSPGManager::PyInit_StrFramework,
                                                      "Strategies",
                                                      "Test-Python3.py" );
#else
    //Python 2.7
    myPyGEmSManager = new NSPGManager::PyGEmSManager("StrFramework", &NSPGManager::initStrFramework,
                                                      "Strategies",  "Test-Python2.py");
#endif

    bp::object Strategy = myPyGEmSManager->getModuleAttrib( "Strategy" );

    Container _Container;
    StrategyParams lStrategyParams;
    unsigned int vecSize = 10;
    unsigned int numResizedNodesInPython = 15;
    for( unsigned int i = 0; i < vecSize; ++i )
    {
      lStrategyParams.stringParam =
        "MyTest_" + std::to_string( lStrategyParams.intParam ) + "_";
      lStrategyParams.intParam++;
      _Container.addElement( lStrategyParams );
    }
    bp::object _strategy = Strategy( _Container );

    std::cout
      << "Initial vector (Showing only string (from base class) parameter)."
      << std::endl;
    for( unsigned int i = 0; i < vecSize; ++i )
      std::cout << _Container.getContainer( )[i].stringParam << std::endl;

    std::string injectedVarName = "vecIn";
    std::string injectedVarName3 = "listOut";

    //BPCode
    myPyGEmSManager->getModule( ).attr( injectedVarName.c_str( )) =
      _Container.getContainer( );
    myPyGEmSManager->getModule( ).attr( injectedVarName3.c_str( )) = 0;

    std::cout << "Initial vector dimensions. Value:"
              << _Container.getContainer( ).size( ) << std::endl;

    std::cout << "Set new dimensions of the vector to python. Value:"
              << numResizedNodesInPython << std::endl;
    _strategy.attr( "setContainerResizeDimension" )( numResizedNodesInPython );

    std::cout << "Calling python methods from CPP." << std::endl;

    _strategy.attr( "simplify" )( );
    _strategy.attr( "fix" )( );
    _strategy.attr( "enhance" )( );
    _strategy.attr( "userDefined" )( );

    std::cout << "Recovering new container from Python." << std::endl;
    bp::list result =
      myPyGEmSManager->extractListFromModule( injectedVarName3.c_str( ));

    int n = bp::len( result );
    std::cout << "Container recovered dimensions Value:" << n << std::endl;

    std::cout << "Showing received string value (modified on python):"
              << std::endl;
    for( int i = 0; i < n; ++i )
    {
      StrategyParams val = bp::extract < StrategyParams >( result[i] );
      std::cout << val.stringParam << std::endl;;
    }

    //Ping pong test
    std::cout << "Starting ping-pong test:" << std::endl;
    _strategy.attr( "eval" )( );

    std::cout << std::endl;

    delete myPyGEmSManager;
  }
  catch( const bp::error_already_set& )
  {
    std::cerr << ">>> Error! Uncaught exception:\n";
    PyErr_Print( );
  }
}
