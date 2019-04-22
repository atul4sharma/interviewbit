
//  https://www.interviewbit.com/problems/zigzag-string/

#include <ios tream>
#include <vector>
#include <string>

//P.......A........H.......N
//..A..P....L....S....I...I....G
//....Y.........I........R
//
//A....C
//...B....D


void print_zig_zag(std::vector<std::vector<char>> const & x)
{
    for(std::size_t i = 0; i < x.size(); ++i)
    {
        for(std::size_t j = 0; j < x[i].size(); ++j)
        {
            std::cout << x[i][j];
        }
        std::cout << "\n";
    }
}

std::string convert(std::string A, int B)
{
    if( B == 1)
        return A;
    std::vector<std::vector<char>> zig_zag{};
    for(int i = 0; i < B; ++i)
    {
        zig_zag.push_back( std::vector<char>( A.size(), '.') );
    }

    std::size_t i = 0;
    int row = 0;
    bool increase_row = true;
    int col = 0;
    while(i < A.size())
    {
        zig_zag[row][col] = A.at(i++);
        ++col;
        row += increase_row ? 1 : -1;
        if(row == B-1 or row == 0)
        {
            increase_row = not increase_row;
        }
    }
    //print_zig_zag(zig_zag);

    std::string result{};
    for(int i = 0 ;i < B; ++i)
    {
        for(std::size_t j = 0; j < zig_zag[i].size(); ++j)
        {
            if( zig_zag[i][j] != '.' )
            {
                result += zig_zag[i][j];
            }
        }
    }
    return result;
}


int main()
{
    //std::string a{"PAYPALISHIRING"};
    //std::cout << "Converted -> " << convert(std::string{"PAYPALISHIRING"}, 3);
    std::cout << "Converted -> " << convert(std::string{"kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS"}, 2);

    return 0;
}
