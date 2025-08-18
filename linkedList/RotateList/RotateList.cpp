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