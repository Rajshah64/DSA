// Problem number 61 on leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        int cnt = 0;
        ListNode *temp = head;
        ListNode *temp2 = nullptr;
        ListNode *nextNode = nullptr;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        temp = head;
        k = k % cnt;
        if (k == 0)
            return head; // we only want within the length of the list .
        int newK = cnt - k;
        for (int i = 0; i < newK - 1; i++)
        {
            temp = temp->next;
        }
        nextNode = temp->next;
        temp->next = nullptr;
        temp2 = nextNode;
        while (temp2->next)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        head = nextNode;
        return head;
    }
};

/// this is the same approach but better written and actually takes less time(micro less time as the above code is also correct but this only does 1 traversal almost).

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length and last node
        int n = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            n++;
        }

        // Step 2: Make it circular
        tail->next = head;

        // Step 3: Find new tail (n - k % n - 1 steps from head)
        k = k % n;
        int stepsToNewTail = n - k - 1;
        ListNode *newTail = head;
        for (int i = 0; i < stepsToNewTail; i++)
        {
            newTail = newTail->next;
        }

        // Step 4: Set new head, break circle
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
