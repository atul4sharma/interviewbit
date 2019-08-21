
// https://www.interviewbit.com/problems/subsets-ii/
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


auto operator << (std::ostream & out, std::vector<int> const & A)
    -> std::ostream &
{
    out << "[";
    std::copy(A.begin(), A.end(), std::ostream_iterator<int>(out, ", "));
    out << "]";
    return out;
}

auto operator << (std::ostream & out, std::vector<std::vector<int>> const & A)
    -> std::ostream &
{
    out << "{ ";
    for(auto const & item : A)
    {
        out << item;
    }
    out << " }";
    return out;
}

template <typename Iter>
auto subsets_impl(Iter                            first
                 ,Iter                            last
                 ,std::vector<std::vector<int>> & result)
    -> void
{
    if(first != last)
    {
        subsets_impl(first + 1, last, result);

        auto current_element = *first;
        auto current_subsets = std::vector<std::vector<int>>{std::vector<int>{current_element}};

        std::transform(result.begin()
                      ,result.end()
                      ,std::back_inserter(current_subsets)
                      ,[&current_element] (std::vector<int> const & item)
                                          {
                                              auto v = item;
                                              v.insert(v.begin(), current_element);
                                              return v;
                                          });
        result.insert(result.begin(), current_subsets.begin(), current_subsets.end());
        
    }
}

std::vector<std::vector<int> > subsetsWithoutDups(std::vector<int> & A) 
{
    if( A.size() == 0 )
        return std::vector<std::vector<int>>{};

    auto result = std::vector<std::vector<int>>{};
    std::sort(A.begin(), A.end());
    subsets_impl(A.begin(), A.end(), result);
    result.insert(result.begin(), std::vector<int>{});
    return result;
}

int main()
{
    auto v = std::vector<int>{1,2,3,4};
    auto result = subsetsWithoutDups(v);
    std::cout << result << "\n";
}
