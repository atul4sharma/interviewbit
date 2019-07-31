
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



std::vector<int> grayCode(int const A) 
{
    if( A == 0 )
    return std::vector<int>{};

    auto result = std::vector<int>{0,1};

    for(int i = 1; i < A; ++i)
    {
        std::size_t const num_to_add = std::pow(2, i);
        auto temp = result;
        std::transform(std::make_move_iterator(temp.rbegin())
                      ,std::make_move_iterator(temp.rend())
                      ,std::back_inserter(result)
                      ,[&num_to_add](int i){return i + num_to_add;});
    }

    return result;
}

int main(int argc, char ** argv)
{
    int num = std::stoi(argv[1]);
    std::cout << grayCode(num) << "\n";
    return 0;
}
