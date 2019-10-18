//if two people with different speeds are running in a circular track, they will
//meet somewhere.
//if it is a straight track, faster one will reach the end.

bool hasCycle(ListNode *head) {

    if(head==NULL)
        return false;

    ListNode *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(fast==slow)
            return true;

        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}
