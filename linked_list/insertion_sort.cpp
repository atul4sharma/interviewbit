
// https://www.interviewbit.com/problems/insertion-sort-list/

#include <iostream>

struct ListNode 
{
    explicit ListNode(int value)
        :val{value}
    {}

    int        val{};
    ListNode * next{NULL};
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

auto delete_list(ListNode ** head)
    -> void
{
    if( *head == NULL )
        return;

    ListNode * temp = (*head)->next;
    delete *head;
    *head = NULL;
    delete_list(&temp);
}


void sortedInsert(ListNode ** head_ref, ListNode * new_node) 
{ 
    ListNode* current; 
    
    if (*head_ref == NULL || (*head_ref)->val >= new_node->val) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->val < new_node->val) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 


ListNode* insertionSortList(ListNode* A) 
{
    if( A == NULL or A->next == NULL)
        return A;
    
    ListNode *sorted = NULL; 
    ListNode *current = A; 
    while (current != NULL) 
    { 
        ListNode *next = current->next; 
        sortedInsert(&sorted, current); 
        current = next; 
    } 
  return sorted;
}


int main()
{
    ListNode * head = NULL;
    create_list(&head, {2,3,1});
    print_list(std::cout, head);
    insertionSortList(head);
    std::cout << "After insertion sort";
    print_list(std::cout, head);
}
