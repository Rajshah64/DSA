#include <bits/stdc++.h>

using namespace std;

// Linked list is a data structure in which it is not stored in a contigious location in the heap memory.
// It is similar to array but its size can be increased at any moment and can have any datatype too!!

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

int searchLL(Node *head, int a)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        if (temp->data == a)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

void Delete(Node *head, int a)
{
    Node *temp1 = head;
    Node *temp = nullptr;
    while (temp1->next != nullptr)
    {
        if (temp1->data == a)
        {
            temp->next = temp1->next;
            temp1->next = nullptr;
            cout << temp1->data << endl;
            delete temp1;
        }
        temp = temp1;
        temp1 = temp1->next;
    }
    cout << "never enetered the loop";
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = convertArrtoLL(a);
    Node *temp = head;
    // cout << "\n the item 2 is present at: " << searchLL(head, 2) << endl;

    // cout << "\nThe element you want to delete is 2. " << endl;
    Delete(head, 1);
    // the below code is for length of the linked list.
    // int count = 0;
    //  while (temp)
    //  {
    //      cout << temp->data << " ";
    //      temp = temp->next;
    //      count++;
    //  }
    //  cout << "\nthe length of the linked list is: " << count << endl;
    return 0;
}