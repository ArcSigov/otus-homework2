#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<std::string>> ip_pool;


template <typename ... Args> 
decltype(auto) filter(Args ... args)
{
    std::vector<std::string> vect_ip_tasks;
    std::vector<std::vector<std::string>> filtered_pool;
    int a[sizeof ... (Args)] = {static_cast<int>(args)...};
    for (unsigned long i = 0 ; i < (sizeof... (Args)); ++i)
    {
        vect_ip_tasks.push_back(std::to_string(a[i]));
    }
    for (auto it = ip_pool.cbegin(); it != ip_pool.cend();it++)
    {
        auto s_vector = *it;
        auto counter = 0;
        if (sizeof ... (Args) <=4)
        {
            for (unsigned long i = 0; i < (sizeof...(Args));  i++)
            {
                if (s_vector[i] == vect_ip_tasks[i])
                    counter++;
            }
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