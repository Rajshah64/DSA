// Problem no. 25 on leetcode.

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
// class Solution
// {
// private:
//     // reverses a linked list and returns new head
//     ListNode *reverseLinkedList(ListNode *head)
//     {
//         ListNode *prev = nullptr;
//         ListNode *curr = head;
//         while (curr)
//         {
//             ListNode *nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//         }
//         return prev;
//     }

//     // get kth node from temp
//     ListNode *getKthNode(ListNode *temp, int k)
//     {
//         while (temp != nullptr && k > 1)
//         {
//             k--;
//             temp = temp->next;
//         }
//         return temp;
//     }

// public:
//     ListNode *reverseKGroup(ListNode *head, int k)
//     {
//         if (!head || !head->next || k == 1)
//             return head;

//         ListNode *temp = head;
//         ListNode *prevLast = nullptr;

//         while (temp != nullptr)
//         {
//             ListNode *kthNode = getKthNode(temp, k);
//             if (kthNode == nullptr)
//             {
//                 if (prevLast)
//                     prevLast->next = temp;
//                 break;
//             }

//             ListNode *nextNode = kthNode->next;
//             kthNode->next = nullptr;

//             ListNode *newHead = reverseLinkedList(temp);

//             if (temp == head)
//             {
//                 head = newHead;
//             }
//             else
//             {
//                 prevLast->next = newHead;
//             }

//             prevLast = temp;
//             temp = nextNode;
//         }
//         return head;
//     }
// };

// NOw the recursive method

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int count = 1;

        ListNode *temp = head;
        ListNode *prev = NULL;

        while (count <= k && temp)
        {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            count++;
        }

        if (count <= k)
        {

            temp = prev;
            prev = NULL;

            while (temp)
            {
                ListNode *nextNode = temp->next;
                temp->next = prev;
                prev = temp;
                temp = nextNode;
            }
        }
        else
        {
            ListNode *oldHead = head;
            head->next = temp;
            head = prev;

            oldHead->next = reverseKGroup(temp, k);
        }

        return head;
    }
};