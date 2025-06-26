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

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = head;
    Node *q = p->next;
    Node *r = q->next;
    while (q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if (r != NULL)
        {
            r = r->next;
        }
    }
    head->next = NULL;
    head = p;
    delete q;
    delete r;
    return head;
}

Node *reverseList2(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    delete temp;
    return head;
}

Node *reverseList3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseList3(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{

    return 0;
}