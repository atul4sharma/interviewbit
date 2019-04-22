
//https://www.interviewbit.com/problems/add-binary-strings/


#include <iostream>
#include <utility>
#include <algorithm>
#include <string>


int add_bits(bool a, bool b, bool & carry)
{
    //std::cout << "carry [" << carry << "]  ";
    bool res = false;
    if( carry and a and b)
    {
        res = true;
        carry = true;
    }
    else if( (a and b) or (a and carry) or (b and carry) )
    {
        res = false;
        carry = true;
    }
    else
    {
        res = a or b or carry;
        carry = false;
    }
    //std::cout << "(" << a << ", " << b << ") -> " << res << "\t" << carry << '\n'; 

    return int(res);
}

using string = std::string;
string addBinary(string A, string B)
{
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    
    bool carry = false;
    std::size_t i = 0;
    std::size_t j = 0;
    std::string result{};
    while(i < A.size() and j < B.size())
    {
        result += std::to_string(add_bits(A[i++] - 48, B[j++] -48, carry));
    }
    
    while(i < A.size())
    {
        result += std::to_string(add_bits(A[i++] - 48, 0, carry));
    }
    while(j < B.size())
    {
        result += std::to_string(add_bits(0, B[j++] -48, carry));
    }
    if( carry )
        result += '1';
    std::reverse(result.begin(), result.end());
    
    return result;
    
}



int main()
{
    string a{   "1010110111001101101000"};
    string b{"1000011011000000111100110"};
    //        1001110001111010101001110
    std::cout << addBinary(a, b) << "\n";
}
