
// https://www.interviewbit.com/problems/array-3-pointers/


#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>

int solve(std::vector<int> const & A, std::vector<int> const & B, std::vector<int> const & C)
{
    int minimum = std::numeric_limits<int>::max();
    int a = A.size() - 1; int b = B.size() - 1; int c = C.size() - 1;
    while(a >= 0 and b >= 0 and c >= 0)
    {
        int x = std::abs(A[a] - B[b]);
        int y = std::abs(B[b] - C[c]);
        int z = std::abs(C[c] - A[a]);

        int val = std::max(x, std::max(y, z));
        if( val < minimum )
            minimum = val;

        if( val == x)
        {
            if( A[a] > B[b] )
                --a;
            else
                --b;
        }
        else if( val == y )
        {
            if( B[b] > C[c] )
                --b;
            else
                --c;
        }
        else
        {
            if( C[c] > A[a] )
                --c;
            else
                --a;
        }
    }
    return minimum;
}

int main()
{

    int a, b, c;


    std::cin >> a;
    std::vector<int> A(a);   
    for(int i = 0; i < a; ++i)
        std::cin >> A[i];

    std::cin >> b;
    std::vector<int> B(b);
    for(int i = 0; i < b; ++i)
        std::cin >> B[i];

    std::cin >> c;
    std::vector<int> C(c);
    for(int i = 0; i < c; ++i)
        std::cin >> C[i];

    std::cout << solve(A, B, C) << "\n";


}
