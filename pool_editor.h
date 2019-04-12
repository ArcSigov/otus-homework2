#include <iostream>
#include <vector>
#include <string>

static inline
void inserter(std::vector<std::vector<std::string>> &vectr)
{
        for (auto it = vectr.begin(); it!= vectr.end();++it)
        {  
            for (auto it1 = it->begin(); it1 != it->end();++it1)
            {
                auto str = *it1;
                auto pos = 0;
                while (str.length() != 3)
                {
                    str.insert(str.begin()+pos,'0'); 
                    pos++;
                }
                //std::swap(*it1, str);
                *it1 = std::move(str);

            }
        }
}

static inline
void eraser(std::vector<std::vector<std::string>> &vectr)
{
        for (auto it = vectr.begin(); it!= vectr.end();++it)
        {
            for (auto it1 = it->begin(); it1 != it->end();++it1)
            {
                 auto str = *it1;
                 str.erase(0,str.find_first_not_of('0'));
                 //!< отсечка удаления октанта "0"
                 if (str.length() == 0)
                 {
                     str.push_back('0');
                 }
                *it1 = std::move(str);
            }
        }
}
