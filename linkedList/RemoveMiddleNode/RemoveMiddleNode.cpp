#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }

    Node(int data1, Node *x)
    {
        data = data1;
        next = x;
    }
};

Node *deleteMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head, *fast = head, *ptr = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        ptr = slow;
        slow = slow->next;
    }
    ptr->next = slow->next;
    slow->next = NULL;
    delete slow;
    // after this loop slow is the middle child.
    // We dont care about the fast
    return head;
}

int main()
{

    return 0;
}