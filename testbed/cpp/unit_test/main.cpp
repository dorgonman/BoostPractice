#define BOOST_TEST_MODULE testbedTestCase
//#include <boost/test/included/unit_test.hpp>
//#include <boost/test/test_case_template.hpp>
//#include <boost/mpl/list.hpp>
#include "unit_test/Test1.hpp"
#include "unit_test/Test2.hpp"
//using namespace boost::unit_test;


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
