
// https://www.interviewbit.com/problems/generate-all-parentheses-ii/


#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional> 


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


std::vector<std::string> cross_product(std::vector<std::string> const & l
                                      ,std::vector<char>        const & r)
{
    std::vector<std::string> result{};
    std::cout << "left " << l << "\n";
    std::cout << "right " << r << "\n";
    for(std::size_t i = 0; i < l.size(); ++i)
    {
        for(std::size_t j = 0; j < r.size(); ++j)
        {
            result.emplace_back(l[i] + r[j] );
        }
    }
    return result;
}

std::vector<std::string> generateParanthesis(int A) 
{
    auto result = std::vector<std::string>{};

    auto input_values = std::vector<char>{};
    std::fill_n(std::back_inserter(input_values), A, '(');
    std::fill_n(std::back_inserter(input_values), A, ')');

    do
    {
        result.emplace_back(std::string{input_values.begin(), input_values.end()});
    }while(std::next_permutation(input_values.begin(), input_values.end()));

    auto not_valid_expression = [](std::string A)
    {
        int open_brace_count = 0;
        for(auto ch: A)
        {
            open_brace_count += ch == '(' ? 1 : -1;
            if(open_brace_count < 0)
                return true;
        }
        return open_brace_count != 0;
    };

    result.erase(std::remove_if(result.begin(), result.end(), not_valid_expression)
                ,result.end());

    return result;
}

int main()
{
    std::cout << generateParanthesis(4) << "\n";
}
