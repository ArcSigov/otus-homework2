#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "filters.h"
#include "pool_editor.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
auto split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void ip_log(const std::vector<std::vector<std::string>> &vectr)
{
    for(auto ip = vectr.cbegin(); ip != vectr.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main()
{
    try
    {
        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }


        inserter(ip_pool);
        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(),ip_pool.end(),std::greater<std::vector<std::string>>());
        eraser(ip_pool);
        //print sorted ip vector
         ip_log(ip_pool);
        
        //print filtered ip vector with first byte 1
         auto ip = filter(1);
         ip_log(ip);
         ip.clear();
        //print filtered ip vector with first byte 46, second 70
         ip = filter(46,70);
         ip_log(ip);
         ip.clear();
        //print filtered ip vector with any byte 46
         ip = filter_any(46);
         ip_log(ip);
         ip.clear();

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
   return 0;
}