
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &A, std::vector<int> &B)
{
    auto const a_size = A.size();
    std::copy(B.begin(), B.end(), std::back_inserter(A));
    std::inplace_merge(A.begin(), A.begin() + a_size, A.end());
}


int main()
{
    auto a = std::vector<int>{-4,3};
    auto b = std::vector<int>{-2,2};

    merge(a, b);

    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";
}
