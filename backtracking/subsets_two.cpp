
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

auto prepend(std::size_t                      val
            ,std::vector<std::vector<int>> & v)
    -> std::vector<std::vector<int>>
{
    for(auto & row : v)
    {
        row.push_back(val);
        std::rotate(row.begin(), row.end() - 1, row.end());
        //std::cout << "row is " << row << "\t";
    }
    return v;
}

template <typename Iter>
auto subsets_impl(Iter first
                 ,Iter last)
    -> std::vector<std::vector<int> >
{
    if( first == last )
        return std::vector<std::vector<int>>{};

    auto final_result = std::vector<std::vector<int> >{std::vector<int>{*first}};
    auto next_iter    = first + 1;
    auto _subsets = subsets_impl(next_iter, last);
    for(auto const & item : _subsets)
        final_result.emplace_back(item);
    auto rest_subsets = prepend(*first, _subsets);
    for(auto const & item : rest_subsets)
        final_result.emplace_back(item);
    return final_result;
}

std::vector<std::vector<int> > subsetsWithDup(std::vector<int> & A) 
{
    std::sort(A.begin(), A.end());
    return subsets_impl(A.begin(), A.end());
}

int main()
{
    auto v = std::vector<int>{1,2,2};
    auto result = subsetsWithDup(v);
    result.push_back(std::vector<int>{});
    std::sort(result.begin()
             ,result.end()
             );
    result.erase(std::unique(result.begin(), result.end()), result.end());
    std::cout << result << "\n";
}
