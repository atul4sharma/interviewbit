

// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/


#inlcude
/*  
        current = prev_node->next;
        if(current->val == prev_node->val)
        {
            prev_node->next = current->next;
            current->next = NULL;
        }
        else
        {
            prev_node = current;
        }
*/

/**
 * Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




void sanitize_current(ListNode * head, ListNode * prev, ListNode * current)
{
    ListNode * next_valid = [](ListNode * current)
    {
        bool duplicate = false;
        while(current->next != NULL and current->val == (current->next)->val)
        {
            current->next = (current->next)->next;
            duplicate = true;
        }
        if(duplicate)
            return current->next;
        else
            return current;
    }(current);
    prev->next = next_valid;
}


ListNode* Solution::deleteDuplicates(ListNode* A)
{
    ListNode * prev_node = A;
    ListNode * current;
    
    while( prev_node->next != NULL)
    {
        current = prev_node->next;
        
    }
    return A;
}

