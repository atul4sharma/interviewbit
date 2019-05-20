#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

std::ostream & operator << (std::ostream & out, std::vector<std::string> const & v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(out, ", "));
    return out;
}

std::ostream & operator << (std::ostream & out, std::vector<char> const & v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(out, ", "));
    return out;
}


std::map<char, std::vector<char>> const _mappings{
    {'0', {'0'}},
    {'1', {'1'}},
    {'2', {'a','b','c'}},
    {'3', {'d','e','f'}},
    {'4', {'g','h','i'}},
    {'5', {'j','k','l'}},
    {'6', {'m','n','o'}},
    {'7', {'p','q','r','s'}},
    {'8', {'t','u','v'}},
    {'9', {'w','x','y','z'}}
};

std::vector<std::string> cross_product(std::vector<std::string> const & l
                                      ,std::vector<char>        const & r)
{
    std::vector<std::string> result{};
    for(std::size_t i = 0; i < l.size(); ++i)
    {
        for(std::size_t j = 0; j < r.size(); ++j)
        {
            result.emplace_back(l[i] + r[j] );
        }
    }
    return result;
}


std::vector<std::string> letterCombinations(std::string A) 
{
    auto result = std::vector<std::string>{};

    auto input_values = std::vector<std::vector<char>>{};

    for(auto ch : A)
        input_values.emplace_back(_mappings.at(ch));

    result.emplace_back(std::string{});
    for(std::size_t i = 0; i < input_values.size(); ++i)
    {
        result = cross_product(result, input_values.at(i));
    }

    std::sort(result.begin(), result.end());
    return result;
}

int main()
{
    std::cout << letterCombinations("233") << "\n";
}
