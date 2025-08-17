// question solved on gfg

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // code here
        Node *temp = head;

        while (temp && temp->next)
        {
            if (temp->data == temp->next->data)
            {
                Node *dup = temp->next;
                temp->next = dup->next;
                if (dup->next)
                    dup->next->prev = temp;
                delete dup;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};