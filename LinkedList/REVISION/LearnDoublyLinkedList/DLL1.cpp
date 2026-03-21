// This file contains the following answers

// What is a doubly linked list
// A doubly linked list is a linear data structure where each node has pointers to both the next and the previous node.
// This allows bidirectional traversal (forward and backward) and efficient insertion/deletion at any node when the pointer is known.

// Representation of it in cpp
// Shown below as class ListNode with int data, ListNode *next, ListNode *prev.
// Constructor initializes data and optional next/prev pointers.

// deletion of Node
// Insertion of Node

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ListNode(int val, ListNode *next, ListNode *prev)
    {
        this->data = val;
        this->next = next;
        this->prev = prev;
    }
}

// array to doubly linked list
ListNode *ArrayToDLL(vector<int> &arr)
{
    ListNode* head=new ListNode(arr[0]);
    ListNode* dummy =head;
    //dummy keeps track of last element.
    int n=arr.size();
    for(int i=1;i<n;i++){
        ListNode* temp= new ListNode(arr[i]);
        temp->prev=dummy;
        dummy->next=temp;
        dummy=temp;

    }
    return head;
}

// print the DLL
void printDLL(ListNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};

    return 0;
}