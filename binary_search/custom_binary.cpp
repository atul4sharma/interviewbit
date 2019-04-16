
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


int main()
{
    //auto const numbers = std::vector<int>{1,2,3,4,5,6,7};
    //auto const numbers = std::vector<int>{8,9,10,11,12,1,2,3,4,5,6,7};
    auto const numbers = std::vector<int>{6,7,8,9,10,11,12,1,2,3,4,5};

    std::cout << "index of pivot " << search_pivot(numbers, 0, numbers.size() -1);
    
    
}
