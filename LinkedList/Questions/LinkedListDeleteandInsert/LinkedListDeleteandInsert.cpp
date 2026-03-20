#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node *t)
    {
        data = data1;
        next = t;
    }
};

Node *convertArrtoLL(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *ptr = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]);
        ptr->next = temp;
        ptr = temp;

        /* code */
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

Node *removeHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        // OR delete head;
        return head;
    }
}

Node *removeLast(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "\n contains only one element and it is deleted now." << endl;
        return head;
    }
    else
    {
        Node *last = head;
        while (last->next->next != NULL)
        {
            last = last->next;
        }
        delete last->next;
        last->next = NULL;
        return last;
    }
}

Node *DeleteKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            temp->next = NULL;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *DeleteElement(Node *head, int el)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (el == temp->data)
        {
            if (temp == head)
            {
                delete prev;
                head = head->next;
                temp->next = NULL;
                delete temp;
                return head;
            }
            prev->next = prev->next->next;
            temp->next = NULL;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *InsertHead(Node *head, int el)
{
    return new Node(el, head);
}

Node *InsertLast(Node *head, int el)
{
    if (head == NULL)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *ans = new Node(el);
    temp->next = ans;
    return head;
}

Node *InsertKthElement(Node *head, int k, int el)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return new Node(el); // this is a very rare edge case.
        }
    }
    if (k == 1)
    {
        return new Node(el, head);
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            Node *newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *InsertElement(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return new Node(el);
    }
    if (head->data == el)
    {
        return new Node(val, head);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == el)
        {
            // cout << "the value is " << temp->next->data << endl;
            Node *x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = convertArrtoLL(a);
    head = InsertElement(head, 4, 10);
    print(head);
    return 0;
}