#ifndef BOOST_TEST_MODULE
#define BOOST_TEST_MODULE GUIViewFSMTestCase
#endif

//#define BOOST_TEST_DYN_LINK
#include "GUIViewFSM.h"
#include <boost/test/unit_test.hpp>
#include <boost/log/trivial.hpp>
#include "StateMachineContext.h"
BOOST_AUTO_TEST_SUITE(GUIViewFSMTestSuit)

BOOST_AUTO_TEST_CASE(GUIViewFSMTestCaseTransision)
{
    BOOST_LOG_TRIVIAL(debug) << "==START GUIViewFSMTestCase==";
    //startGUIViewFSM(); 
    horizon::StateMachineContext<horizon::UGUIViewFSM> sm;
    sm.start();
    sm.processEvent(horizon::events::GameStartEvent());
    sm.processEvent(horizon::events::GameExitToTitleViewEvent());
    sm.stop();
    BOOST_LOG_TRIVIAL(debug) << "==END GUIViewFSMTestCase==";
}
 
 
BOOST_AUTO_TEST_CASE(GUIViewFSMTestCase2)
{
    BOOST_LOG_TRIVIAL(debug) << "==START GUIViewFSMTestCase2==";
  //  Timer t;
   // t.elapsed();
    BOOST_LOG_TRIVIAL(debug) << "==END GUIViewFSMTestCase2==";
    //std::cout << "=============START GUIViewFSMTestCase2==================" << std::endl;
    //startGUIViewFSM();
    //std::cout << "=============END   GUIViewFSMTestCase2==================" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()