// Copyright 2013 Joshua Dentoyan
// showing how to to use timers in MSM
// distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// vending_machine.cpp : Defines the entry point for the console application.
//

#include <exception>
//#include "unit_test/Test1.hpp"
#include "SMSTest.h"
//using namespace boost::unit_test;
/*test_suite* init_unit_test_suite(int)
{
   // framework::master_test_suite().
        //add(BOOST_TEST_CASE(&free_test_function));

    return 0;
}*/

int main(int argc, char* argv[])
{
    //boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);

    start();
    return 0;
}

///*
//void test_case1() { /* ... */ }
//void test_case2() { /* ... */ }
//void test_case3() { /* ... */ }
//void test_case4() { /* ... */ }
//
//test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
//{
//    test_suite* ts1 = BOOST_TEST_SUITE("test_suite1");
//    ts1->add(BOOST_TEST_CASE(&test_case1));
//    ts1->add(BOOST_TEST_CASE(&test_case2));
//
//    test_suite* ts2 = BOOST_TEST_SUITE("test_suite2");
//    ts2->add(BOOST_TEST_CASE(&test_case3));
//    ts2->add(BOOST_TEST_CASE(&test_case4));
//
//    framework::master_test_suite().add(ts1);
//    framework::master_test_suite().add(ts2);
//
//    return 0;
//}*/