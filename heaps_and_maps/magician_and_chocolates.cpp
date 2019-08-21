
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T>
auto operator << (std::ostream & out, std::vector<T> const & v)
    -> std::ostream &
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ", "));
    return out;
}

int nchoc(int A, std::vector<int> &B) 
{
    if(B.size() == 0)
        return 0;

    std::make_heap(B.begin(), B.end());
    auto answer = 0;
    
    while(A--)
    {
        std::pop_heap(B.begin(), B.end());
        auto const largest = B.back();
        answer = answer % 1000000007 + largest % 1000000007;
        B.back() = largest/2;
        std::push_heap(B.begin(), B.end());
    }
    return answer % 1000000007;
}

int main()
{
    auto v = std::vector<int>{2147483647, 2000000014, 2147483647};
    std::cout << nchoc(10, v) << "\n";
    return 0;
}
