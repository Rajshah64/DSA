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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *tort = head, *hare = head;
    while (hare && hare->next)
    {
        tort = tort->next;
        hare = hare->next->next;
    }
    // delete hare;
    Node *ptr = head;
    while (ptr->next != tort)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    while (tort != NULL)
    {
        Node *r = tort->next;
        tort->next = ptr;
        ptr = tort;
        tort = r;
        if (r != NULL)
        {
            r = r->next;
        }
    }
    // delete r;
    tort = head;
    while (tort)
    {
        if (tort->val != ptr->val)
        {
            return false;
        }
        tort = tort->next;
        ptr = ptr->next;
    }
    return true;
}

int main()
{

    return 0;
}