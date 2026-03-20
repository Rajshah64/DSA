// solved on gfg
//  User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        // Write your code here
        Node *temp = *head_ref;

        while (temp)
        {
            if (temp->data == x)
            {
                Node *toDelete = temp;

                if (temp == *head_ref)
                {
                    *head_ref = temp->next;
                    if (*head_ref)
                        (*head_ref)->prev = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;
                    if (temp->next)
                        temp->next->prev = temp->prev;
                }

                temp = temp->next;
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};

// OR
class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        Node *temp = *head_ref;

        while (temp)
        {
            if (temp->data == x)
            {
                Node *nextNode = temp->next;
                Node *prevNode = temp->prev;

                // if deleting head
                if (temp == *head_ref)
                {
                    *head_ref = nextNode;
                }

                if (nextNode != NULL)
                    nextNode->prev = prevNode;
                if (prevNode != NULL)
                    prevNode->next = nextNode;

                delete temp;
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};
