ListNode* reverseList(ListNode* head) {
    ListNode *current,*prev,*nextt;

    if(head==NULL)
        return NULL;

    current=head;
    prev=NULL;

    while(current!=NULL)
    {
        nextt=current->next;
        current->next=prev;
        prev=current;
        current=nextt;
    }
    head=prev;

    return head;
}
