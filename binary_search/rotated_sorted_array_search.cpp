
// Problem : https://www.interviewbit.com/problems/rotated-sorted-array-search/

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


auto search_pivot(const std::vector<int> & A, std::size_t first, std::size_t last)
    -> std::size_t
{
    if( first == last )
        return first;
    std::size_t middle = (first + last)/2;
    std::cout << "Checking " << first << ", " << last << "\n";
    bool first_valid  = A.at(first) <= A.at(middle);
    bool second_valid = A.at(middle) <= A.at(last);
    if(not first_valid)
    {
        return search_pivot(A, first, middle);
    }
    else if(not second_valid)
    {
        return search_pivot(A, middle + 1, last);
    }
    else
    {
        return first;
    }

}

int search(const std::vector<int> &A, int B)
{    
    auto const pivot_index = search_pivot(A, 0, A.size() -1 );
    //auto second_range_start = std::adjacent_find(A.begin(), A.end(), std::greater<int>{});
    auto second_range_start = A.begin() + pivot_index;
    // implies range is sorted
    if( second_range_start == A.end() )
    {
        auto result_iter = std::lower_bound(A.begin(), A.end(), B);
        return result_iter != A.end()
               ? *result_iter == B 
                 ? std::distance(A.begin(), result_iter) 
                 : -1 
               : -1;        

    }
    //std::advance(second_range_start, 1);
    auto second_range_end       = A.end();
    bool b_lies_in_second_range = (B >= *second_range_start and B <= *(second_range_end - 1));
    bool b_lies_in_first_range  = (B >= *A.begin() and B <= *(second_range_start - 1));
    
    auto result_iter = [&]()
    {
        if(b_lies_in_first_range)
            return std::lower_bound(A.begin(), second_range_start, B);
        else if(b_lies_in_second_range)
            return std::lower_bound(second_range_start, A.end(), B);
        else
            return A.end();
    }();
    
    return result_iter != A.end()
           ? *result_iter == B 
             ? std::distance(A.begin(), result_iter) 
             : -1 
           : -1;
}

int main()
{
    //auto const numbers = std::vector<int>{180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177 };
    //auto const numbers = std::vector<int>{19, 20, 21, 22, 28, 29, 32, 36, 39, 40, 41, 42, 43, 45, 48, 49, 51, 54, 55, 56, 58, 60, 61, 62, 65, 67, 69, 71, 72, 74, 75, 78, 81, 84, 85, 87, 89, 92, 94, 95, 96, 97, 98, 99, 100, 105, 107, 108, 109, 110, 112, 113, 115, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 128, 130, 131, 133, 134, 135, 136, 137, 138, 139, 141, 142, 144, 146, 147, 148, 149, 150, 153, 155, 157, 159, 161, 163, 164, 169, 170, 175, 176, 179, 180, 185, 187, 188, 189, 192, 196, 199, 201, 203, 205, 3, 7, 9, 10, 12, 13, 17 };
    auto const numbers = std::vector<int>{1,2,3,4,5,6,7};
    int B = 2;
    
    std::cout << "answer -> " << search(numbers, B) << "\n";
    
    
}
