#define BOOST_TEST_MODULE ip_test_module

#include "filters.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ip_filtration_test_suite)

//Тест проверки фильтров (по умолчанию используется эталлоный ip! на выходе из теста ip должен совпадать с эталоном)
BOOST_AUTO_TEST_CASE(filter_bytes) {
    
    std::vector<std::string> arr_strings;
    int arr[4] = {1 , 1 , 234, 8};

    for (auto i = 0 ; i < 4 ; i++)
    {
        arr_strings.push_back(std::to_string(arr[i]));
    }

    ip_pool.push_back(arr_strings);

    auto ip = filter(1,1,234,8);
    BOOST_CHECK(ip == ip_pool);
    ip = filter(1,1,234);
    BOOST_CHECK(ip == ip_pool);
    ip = filter(1,1);
    BOOST_CHECK(ip == ip_pool);
    ip = filter(1);
    BOOST_CHECK(ip == ip_pool);

    ip_pool.clear();
    
}

BOOST_AUTO_TEST_CASE(filter_any_byte)
{
    std::vector<std::string> arr_strings;
    int arr[4] = {45 , 46 , 47, 48};
    for (auto i = 0 ; i < 4 ; i++)
    {
        arr_strings.push_back(std::to_string(arr[i]));
    }
    ip_pool.push_back(arr_strings);

    auto ip_any = filter_any(46);
    BOOST_CHECK(ip_any == ip_pool);
     ip_any = filter_any(46);
    BOOST_CHECK(ip_any == ip_pool);
    ip_any = filter_any(47);
    BOOST_CHECK(ip_any == ip_pool);
    ip_any = filter_any(48);
    BOOST_CHECK(ip_any == ip_pool);

}
BOOST_AUTO_TEST_SUITE_END()