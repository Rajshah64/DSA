// Leetcode Question 234

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
    bool isPalindrome(ListNode *head)
    {
        // step 1 is to traverse and know the elements
        // step 2 is reverse the linked list
        // step 3 is to traverse it and compare

        // step1
        vector<int> el;
        ListNode *temp = head;
        while (temp)
        {
            el.push_back(temp->val);
            temp = temp->next;
        }

        // step2
        ListNode *p = nullptr;
        ListNode *q = head;
        while (q)
        {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        // step 3
        temp = p;
        int n = el.size();
        for (int i = 0; i < n; i++)
        {
            if (temp->val != el[i])
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
};