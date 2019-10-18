ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *temp=head,*temp2;

    if(temp->next==NULL)
        return NULL;

    while(temp->next != NULL)
    {
        temp2=temp;

        int i=n;
        while(i--)
            temp2=temp2->next;

        //nth element is the first element
        if(temp2==NULL)
        {
            head=temp->next;
            break;
        }

        //temp is the (n+1)th element from end
        if(temp2->next==NULL)
        {
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return head;
}
