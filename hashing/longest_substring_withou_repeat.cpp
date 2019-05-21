
// https://www.interviewbit.com/problems/longest-substring-without-repeat/

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

int longestUniqueSubsttr(std::string const & str) 
{ 
    auto current_length = 1;
    auto max_length     = 1; // result
    auto prev_index     = 0; // previous index
    auto visited = std::vector<int>(257, -1);

	visited[str[0]] = 0; 

	for(std::size_t i = 1; i < str.size(); ++i)
    { 
		prev_index = visited.at(str[i]); 

		if (prev_index == -1 || i - current_length > prev_index) 
        {
			++current_length; 
        }
		else
        { 
			if (current_length > max_length) 
				max_length = current_length; 

			current_length = i - prev_index; 
		} 

		visited[str[i]] = i; 
	} 

	if (current_length > max_length) 
		max_length = current_length; 

	return max_length; 
}

int main()
{
    std::cout << longestUniqueSubsttr(std::string{"abcabcbb"}) << "\n";
    return 0;
}

