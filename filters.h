#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

std::vector<std::vector<std::string>> ip_pool;


template <typename ... Args> 
decltype(auto) filter( Args ... args)
{
    if (sizeof ... (Args)> 4)
        throw std::bad_alloc();

    std::vector<std::string> vect_ip_tasks = {std::to_string(args)...};
    std::vector<std::vector<std::string>> filtered_pool;
 
    for (auto it = ip_pool.cbegin(); it != ip_pool.cend();it++)
    {
        auto s_vector = *it;
        auto counter = 0;
        for (unsigned long i = 0; i < (sizeof...(Args));  i++)
        {
            if (s_vector[i] == vect_ip_tasks[i])
                counter++;
        }
        if (counter == sizeof ...(Args)) filtered_pool.push_back(*it);
    }
    return filtered_pool;
}

auto filter_any(int value)
{
    std::vector<std::vector<std::string>> filtered_pool;
    for (auto it = ip_pool.cbegin(); it !=ip_pool.cend();it++)
    {
        auto finded = std::find(it->begin(),it->end(),std::to_string(value));
        if (finded != it->end())
        {
            filtered_pool.push_back(*it);
        }    
    }
    return filtered_pool;
} 
