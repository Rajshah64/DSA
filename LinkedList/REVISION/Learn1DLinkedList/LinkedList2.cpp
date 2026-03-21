// Things that will be covered in this file:

// 1. Insertion of 4 types in a linked list which are
//    a. Insertion at the end of the linked list
//    b. Insertion at the beginning of the linked list
//    c. Insertion at a given position/value in the linked list

// 2. Deletion of 4 types in a linked list which are
//    a. Deletion at the end of the linked list
//    b. Deletion at the beginning of the linked list
//    c. Deletion at a given position/value in the linked list
//    d. Deletion of a given key in the linked list

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

// I will name each insertion and deletion with a number.

// Insertion at head
ListNode *insertHead(ListNode *head, int val)
{
    if (!head)
        return new ListNode(val);
    ListNode *temp = new ListNode(val);
    temp->next = head;
    return temp;
}

// Insertion at tail
ListNode *insertTail(ListNode *head, int val)
{
    if (!head)
        return new ListNode(val);
    ListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Insertion at given k position position
// Here if k=1, that means it will come before index 1 (becomes new head).
// so if k=6 and ll.length is 5 it will insert at tail.
ListNode *insertK(ListNode *head, int k, int val)
{
    if (k <= 1)
    {
        return insertHead(head, val);
    }

    if (!head)
    {
        // empty list and k > 1: can't insert at position greater than 1
        return nullptr;
    }

    ListNode *temp = head;
    int pos = 1;

    // Move to node at position k-1 or tail (whichever comes first)
    while (temp->next && pos < k - 1)
    {
        temp = temp->next;
        pos++;
    }

    // now temp is either (k-1)th node or last node
    ListNode *node = new ListNode(val);
    node->next = temp->next;
    temp->next = node;
    return head;
}

// Insertion before a given value. In this case we wont insert before head
// cause the question would not ask you to change the head.
ListNode *insertVal(ListNode *head, int target)
{
    if (!head || head->data == target)
        return head; // no insertion before head

    ListNode *temp = head;
    while (temp->next && temp->next->data != target)
    {
        temp = temp->next;
    }

    if (!temp->next)
        return head; // target not found

    ListNode *node = new ListNode(target);
    node->next = temp->next;
    temp->next = node;
    return head;
}

// Delete at head
ListNode *removeHead(ListNode *head)
{
    if (!head)
        return head;
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete at tail
ListNode *removeTail(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *temp = head;
    ListNode *prev;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    // we are at the second last node.
    // temp is the last and prev is second last
    prev->next = temp->next;
    delete temp;
    return head;
}

// Delete at given k position
ListNode *removeK(ListNode *head, int k)
{
    // There can be three cases
    // K=1 , that is remove head
    // K=x , where x is the length of the ll so remove tail
    // K=x, where x can be anything else so we have to remove that node
    if (!head || k <= 0)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    if (k == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
        return head; // k > length
    prev->next = temp->next;
    delete temp;
    return head;
}

// Deletion of a given value. In this case we wont delete before head
ListNode *removeVal(ListNode *head, int val)
{
    if (!head)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    // if val is present in head
    // if val is present in tail
    // if val is present in between
    while (temp)
    {
        if (temp->data == val)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
        return head; // val not found
    if (temp == head)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }
    delete temp;
    return head;
}

int main()
{
    return 0;
}