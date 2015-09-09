#define BOOST_TEST_MODULE testbedTestCase

//#define BOOST_TEST_DYN_LINK

#include "unit_test/GUIViewFSMTestCase.hpp"

/*
BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
BOOST_LOG_TRIVIAL(info) << "An informational severity message";
BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
BOOST_LOG_TRIVIAL(error) << "An error severity message";
BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";*/
//____________________________________________________________________________//
//example --report_level=detailed
//$(TargetPath) --run_test=test_suite2 --report_level=detailed
//"$(TargetPath)" --result_code=no --report_level=no

//if we define #define BOOST_TEST_MODULE xxx in this file, then init_unit_test_suite should not be implemented
//function init_unit_test_suite is for customize our master_test_suite
/*test_suite* init_unit_test_suite(int argc, char* argv[])
{
    typedef boost::mpl::list<int, long, unsigned char> test_types;

   // framework::master_test_suite().
       // add(BOOST_TEST_CASE_TEMPLATE(my_test, test_types));  
    //framework::master_test_suite().add(BOOST_TEST_SUITE(test_suite1));

    return 0;
}*/
 