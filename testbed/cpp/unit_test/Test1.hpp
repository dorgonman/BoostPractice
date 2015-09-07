

//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

int add(int i, int j)
{
    return i + j;
}
BOOST_AUTO_TEST_CASE(universeInOrder)
{
    BOOST_CHECK(add(2, 2) == 4);
}


int multiply(const int x, const int y)
{
    return x * y;
}

BOOST_AUTO_TEST_CASE(SimpleTestInMainTestingModule)
{
    BOOST_CHECK(1 == 2);
}
