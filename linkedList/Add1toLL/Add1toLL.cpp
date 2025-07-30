/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
/*
    You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list.

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457.
Input: LinkedList: 1->2->3
Output: 124

Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124.
*/
class Solution
{
private:
    Node *reverseList(Node *head)
    {
        Node *p = nullptr;
        Node *c = head;
        Node *n = nullptr;

        while (c != nullptr)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }

        return p;
    }

public:
    Node *addOne(Node *head)
    {
        // Your Code here
        head = reverseList(head);
        Node *temp = head;
        int carry = 1;
        while (carry != 0 && temp)
        {
            temp->data = (temp->data + carry) % 10;
            if (temp->data != 0)
                carry = 0;
            if (temp->next == nullptr)
            {
                break;
            }
            temp = temp->next;
        }
        if (carry == 1)
        {
            Node *newNode = new Node(1);
            temp->next = newNode;
            // temp=temp->next;
        }
        head = reverseList(head);
        return head;

        // return head of list after adding one
    }
};