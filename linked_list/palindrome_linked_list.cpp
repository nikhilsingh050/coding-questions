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


    //compare both the halves
    while(secondHalf!=NULL)
    {
        if(firstHalf->val != secondHalf->val)
            return false;
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
    }
    return true;
}
