
// https://www.interviewbit.com/problems/rotate-list/

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

auto print_list(std::ostream & out, ListNode const * head)
    -> std::ostream &
{
    auto current = head;
    while( current )
    {
        out << current->val << "->";
        current = current->next;
    }
    out << "\n";
    return out;
}


auto append(ListNode ** head, int item)
    -> void
{
    ListNode * new_node = new ListNode{item};
    if( *head == NULL )
    {
        *head = new_node;
        return;
    }

    ListNode * current = *head;
    while(current->next != NULL)
    {
        current = current->next;

    }
    current->next = new_node;
}



auto create_list(ListNode ** start, std::initializer_list<int> const & l)
    -> int 
{
    auto counter = int{0};
    for(auto const item : l)
    {
       append(start, item);
       ++counter;
    }
    return counter;
}



auto count_elements(ListNode * head)
    -> int
{
    int counter = 0;
    ListNode * current = head;
    while( current )
    {
        ++counter;
        current = current->next;
    }
    return counter;
}
auto increment_by(ListNode ** A, int n)
    -> void
{
    while( n )
    {
        *A = (*A)->next;
        --n;
    }
}


ListNode* rotateRight(ListNode* A, int B)
{
    ListNode * head = A;
    int num = count_elements(head);
    if( num == 1 )
        return head;

    B = B % num;
    if( B == 0 )
        return head;
    std::cout << "mod -> " << B << "\n";
    ListNode * iter = head;
    increment_by(&iter, num - B -1);
    std::cout << iter->val << "\n";
    ListNode * prev = iter;
    increment_by(&iter, 1);
    prev->next = NULL;

    ListNode * current = iter;

    while(current->next != NULL)
        current = current->next;

    current->next = head;

    return iter;
}



int main()
{
    ListNode * head = NULL;
    create_list(&head, {68 , 86 , 36 , 16 , 5 , 75 });
    ListNode * new_head = rotateRight(head, 90);
    print_list(std::cout, new_head);
    return 0;
}
