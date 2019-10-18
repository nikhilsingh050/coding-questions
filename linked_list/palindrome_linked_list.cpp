//Recursive solution:

//use two pointers.
//one will go till last node with recursion stack
//one will go next with each comparison.

//Time Complexity: O(n)
//Space Complexity: O(1) , O(n) recursion stack space

bool pal(ListNode **left, ListNode *right)
{
    if(right==NULL)
        return true;

    bool res = pal(left, right->next);
    if(res==false)
        return false;

    if((*left)->val==right->val)
    {
        *left=(*left)->next;
            return true;
    }
    return false;

}


bool isPalindrome(ListNode* head)
{
    return pal(&head,head);
}





///////////////////////////////////////////////////////////////////////

//O(n), O(1) solution:

//1. divide in two parts
//2. reverse the second half
//3. compare the two parts

bool isPalindrome(ListNode* head) {

    //divide list in two parts
    ListNode *slow=head,*fast=head,*firstHalf=head,*secondHalf;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    if(fast==NULL)
        secondHalf=slow;
    else
        secondHalf=slow->next;


    //reverse second half
    ListNode *current,*prev,*next;
    current=secondHalf;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current =next;
    }
    secondHalf=prev;


    //compare element of both the halves
    while(secondHalf!=NULL)
    {
        if(firstHalf->val != secondHalf->val)
            return false;
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
    }
    return true;
}
