// This file contains the following problems

// What is a linked list?
// - Linear data structure built from nodes.
// - Each node stores value and pointer to next node (for singly linked list).
// - Uses heap nodes, not contiguous memory like array.

// Where are linked lists used in real life?
// - Stacks/queues implementations.
// - Undo/redo history in editors.
// - Browser history (back/forward) as doubly linked list.
// - Graph adjacency lists.
// - Dynamic memory free lists (allocator internals).

// class in C++
// - Define node type: class ListNode { int data; ListNode* next; }.
// - Constructors initialize members and pointer (next = nullptr or next = node).

// memory space used by linked list
// - Each node allocates sizeof(int) + sizeof(pointer) plus heap metadata.
// - Total = N * node size + allocator overhead.
// - Not constant memory; grows/shrinks with insert/delete.

// difference between Node and Node*
// - Node is value/object; contains data+next.
// - Node* is pointer/address to a Node in memory.
// - `Node` copies data; `Node*` shares same node instance.
// - Linked list links via Node* (next pointers and head pointer).

#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
    ListNode(int x, ListNode *node)
    {
        this->data = x;
        this->next = node;
    }
};

// Array to linked list conversion
ListNode *ArrayToLinkedList(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Traversing a linked list
void LLTraversal(ListNode *head)
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    ListNode *temp = head;
    cout << "Traversed List is: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of a linked list
int LengthLL(ListNode *head)
{
    if (!head)
        return 0;
    ListNode *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Search an element in a linked list
bool SearchLL(int k, ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// Time Complexity of all above operations is O(n) in worst case, where n is the number of nodes in the linked list.

int main()
{
    ListNode *ls;
    vector<int> arr = {1, 2, 3, 4, 5};
    ls = ArrayToLinkedList(arr);
    LLTraversal(ls);
    cout << "The Length of the LinkedList is:-" << LengthLL(ls) << " " << endl;
    int x;
    cout << "Enter the key to search in the linkedlist:- ";
    cin >> x;
    if (SearchLL(x, ls))
        cout << "Yes the key is present in the linkedlist!!" << endl;
    else
        cout << "NO the key is not present in the linkedlist!!" << endl;
    return 0;
}