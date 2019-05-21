//
// https://www.interviewbit.com/problems/pretty-json/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>

template <typename T>
auto operator << (std::ostream & out, std::vector<T> const & v)
    -> std::ostream &
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, "\n"));
    return out;
}

auto append_tabs(std::string & s, int times)
    -> void
{
    int i = 0;
    while(i < times)
    {
        s += '\t';
        ++i;
    }
}

std::vector<std::string> prettyJSON(std::string A)
{
    auto result = std::vector<std::string>{};
    auto current_indent = 0;
    auto ss = std::stringstream{A};
    char ch;
    auto token = std::string{};
    while( ss.get(ch))
    {
        if( ch == '{' or ch == '[' )
        {
            result.push_back(std::move(token));
            token = std::string{};
            append_tabs(token, current_indent);
            token += ch;
            current_indent += 1;
            result.push_back(std::move(token));
            token = std::string{};
            append_tabs(token, current_indent);
        }
        else if( ch == '}' or ch == ']' )
        {
            current_indent -= 1;
            result.push_back(std::move(token));
            token = std::string{};
            append_tabs(token, current_indent);
            token += ch;
        }
        else if( ch == ',')
        {
            token += ch;
            result.push_back(std::move(token));
            token = std::string{};
            append_tabs(token, current_indent);
        }
        else
        {
            token += ch;
        }
    }
    result.push_back(token);

    result.erase(std::remove_if(result.begin()
                               ,result.end()
                               ,[](std::string const & A)
                                  {
                                    return std::find_if(A.begin(), A.end(), [](int ch) {return not std::isspace(ch);}) == A.end();
                                  })
                ,result.end());

    return result;
}

int main()
{
    std::cout << prettyJSON("[\"foo\",{\"bar\":[\"baz\",null,1.0,2]}]") << "\n";
}
