// Leetcode Question 142

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* hare=head, *tor=head;
//         while(hare && hare->next){
//             hare=hare->next->next;
//             tor=tor->next;
//             if(hare==tor) {
//                 tor=head;
//                 while(tor!=hare){
//                     hare=hare->next;
//                     tor=tor->next;
//                 }
//                 return tor;
//             }
//         }
//         return nullptr;
//     }
// };

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *hare = head, *tor = head;
        while (hare && hare->next)
        {
            hare = hare->next->next;
            tor = tor->next;
            if (hare == tor)
            {
                break;
            }
        }
        if (!hare || !hare->next)
            return nullptr;
        tor = head;
        while (tor != hare)
        {
            hare = hare->next;
            tor = tor->next;
        }
        return tor;
    }
};
