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

Node *middleNode(Node *head)
{
    Node *tort = head, *hare = head;
    while (hare && hare->next)
    {
        tort = tort->next;
        hare = hare->next->next;
    }
    return tort;
}

int main()
{

    return 0;
}