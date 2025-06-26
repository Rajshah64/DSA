bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// this is the first method but nod very good as it takes extra space O(n).
// Use the tortoise and Hare method
