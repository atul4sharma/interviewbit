
#include <cmath>
#include <iostream>
#include <algorithm>

int solve(std::vector<int> & A, std::vector<int> & B, std::vector<int> & C) 
{
    int min_diff, current_diff, max_term; 
    int a = A.size() - 1;
    int b = B.size() - 1;
    int c = C.size() - 1;

    min_diff = std::abs(std::max(A[a], std::max(B[b], C[c])) - std::min(A[a], std::min(B[b], C[c]))); 

    while (a >= 0 && b >= 0 && c >= 0)  
    { 
        current_diff = std::abs(std::max(A[a], std::max(B[b], C[c])) - std::min(A[a], std::min(B[b], C[c]))); 

        if (current_diff < min_diff) 
            min_diff = current_diff; 

        max_term = std::max(A[a], std::max(B[b], C[c])); 

        if (A[a] == max_term) 
            --a;
        else if (B[b] == max_term) 
            --b;
        else
            --c;
    } 

    return min_diff;
}



int main()
{
	std::vector<int> A{1,4,5,8,10};
    std::vector<int> B{6,9,15};
    std::vector<int> C{2,3,6,6};
	
    std::cout << solve(A, B, C) << "\n";

}
