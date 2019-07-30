
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

auto concat(char                       prefix
           ,std::vector<std::string> & vec)
    -> void
{
    for(auto & item : vec)
        item = prefix + item;
}

auto gray_code_impl(std::vector<std::vector<std::string>>       & pool
                   ,int                                   const   n)
    -> std::vector<std::string>
{
    if( n == 0 )
    {
        pool[n] = std::vector<std::string>{"0", "1"};
        return pool[n];
    }

    auto prev = gray_code_impl(pool, n-1);
    auto rev  = prev;
    std::reverse(rev.begin(), rev.end());
    concat('0', prev);
    concat('1', rev );
    prev.insert(prev.end(), std::make_move_iterator(rev.begin()), std::make_move_iterator(rev.end()));

    pool[n] = prev;
    return pool[n];

}

std::vector<int> grayCode(int const A) 
{
    if( A == 0 )
    return std::vector<int>{};

    auto pool = std::vector<std::vector<std::string>>(A);
    auto res = gray_code_impl(pool, A-1);

    auto const to_num = [](std::string a)
    {
        return std::stoi(std::move(a), nullptr, 2);
    };

    auto result = std::vector<int>{};
    std::transform(res.begin(), res.end(), std::back_inserter(result), to_num);
    return result;
    
}

int main(int argc, char ** argv)
{
    int num = std::stoi(argv[1]);
    std::cout << grayCode(num) << "\n";
    return 0;
}
