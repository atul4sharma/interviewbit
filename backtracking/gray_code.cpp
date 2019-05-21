
// https://www.interviewbit.com/problems/gray-code/

#include <iostream>
#include <vector>
#include <iterator>
#include <bitset>
#include <cmath>
#include <algorithm>


auto operator << (std::ostream & out,  std::vector<int> const & A)
    -> std::ostream &
{
    std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, ", "));
    return out;
}

auto to_int(std::vector<int> const & A)
    -> int
{
    std::size_t result{};
    for(std::size_t i = 0 ; i < A.size() ; ++i)
    {
        result += std::pow(2, A.size() - i -1 ) * A[i];
    }
    return result;
}

auto to_binary(int a)
    -> std::vector<int>
{
    std::vector<int> result{};

    while(a)
    {
        result.push_back(a%2);
        a = a/2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

auto flip(int & a)
    -> void
{
    a = (a == 0) ? 1: 0;
}

std::vector<int> grayCode(int const A) 
{
    std::vector<int> result{0};
    

    return result;
}


int main()
{
    std::cout << to_binary(10) << "\n";
    std::cout << to_int(std::vector<int>{1,0,1,0}) << "\n";
    std::cout << grayCode(2) << "\n";
    return 0;
}
