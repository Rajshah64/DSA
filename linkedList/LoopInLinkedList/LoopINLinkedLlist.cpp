bool hasCycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    unordered_map<Node *, int> mpp;
    Node *temp = head;
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

bool hasCycle(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *tort = head, *hare = head;
    while (hare && hare->next)
    {
        tort = tort->next;
        hare = hare->next->next;
        if (tort == hare)
        {
            return true;
        }
    }
    return false;
}