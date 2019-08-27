
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T, typename U>
auto operator << (std::ostream & out, std::pair<T, U> const & item)
    -> std::ostream &
{
    out << "(" << item.first << ", " << item.second << ")";
    return out;
}

template <typename T, typename U>
auto operator << (std::ostream & out, std::map<T, U> const & v)
    -> std::ostream &
{
    std::cout << "{";
    for(auto const & item : v)
        std::cout << item << ", ";
    std::cout << "}";
    return out;
}

template <typename T>
auto operator << (std::ostream & out, std::vector<T> const & v)
    -> std::ostream &
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    return out;
}

template <typename Iterator>
auto get_value(std::map<int, int> & counter
              ,Iterator             start
              ,Iterator             to_remove)
    -> int
{
    auto iter = counter.lower_bound(*start);
    if( iter->first == *start )
    {
        ++(iter->second);
    }
    else
    {
        counter.emplace_hint(iter, *start, 1);
    }
    auto prev = counter.lower_bound(*to_remove);
    --(prev->second);
    if( prev->second == 0 )
        counter.erase(prev);

    return counter.size();
}

std::vector<int> dNums(std::vector<int> &A, int B)
{
    if( B > static_cast<int>(A.size()) )
        return std::vector<int>{};

    auto result = std::vector<int>{};
    auto counter = std::map<int, int>{};
    auto start = A.begin();
    auto end   = std::next(start, B);

    while( start != end )
    {
        auto item = counter.emplace(*start, 1);
        if( not item.second )
            ++(item.first->second);
        ++start;
    }
    result.emplace_back(static_cast<int>(counter.size()));

    while( start != A.end() )
    {
        result.emplace_back(get_value(counter, start, std::next(start, -1 * B)));
        ++start;
    }

    return result;
}

int main()
{
    auto v = std::vector<int>{1, 2, 1, 3, 4, 3};
    std::cout << dNums(v, 3) << std::endl;
    return 0;
}
