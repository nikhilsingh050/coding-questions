//similar to merge sort

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;

    //dummy node to hang the result to
    ListNode *head = new ListNode(0);
    ListNode *result=head;

    //add till min length
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val <= l2->val)
        {
            head->next=l1;
            l1=l1->next;
        }
        else
        {
            head->next=l2;
            l2=l2->next;
        }
        head=head->next;
    }

    //add remaining nodes
    if(l1==NULL)
        head->next=l2;
    else if(l2==NULL)
        head->next=l1;

    return result->next;
}
