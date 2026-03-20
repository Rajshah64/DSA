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
    Node *temp = head;
    Node *p = NULL;
    //  Node* ptr=head;
    // while(ptr!=NULL){
    //     cout<< ptr->val<<endl;
    //     ptr=ptr->next;
    // }
    while (temp != NULL)
    {
        Node *r = temp->next;
        temp->next = p;
        p = temp;
        temp = r;
    }
    // cout<< p->val<<" "<<p->next->val<<endl;
    return p;
}

Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL || (head->next == NULL && n == 1))
    {
        return NULL;
    }
    Node *newHead = reverseList(head);
    if (n == 1)
    {
        Node *temp = newHead;
        newHead = newHead->next;
        temp->next = NULL;
        delete temp;
        newHead = reverseList(newHead);
        return newHead;
    }
    int cnt = 0;
    Node *temp = newHead;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == n)
        {
            prev->next = prev->next->next;
            temp->next = NULL;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    newHead = reverseList(newHead);
    return newHead;
}

int main()
{

    return 0;
}