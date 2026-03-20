// The question was solved on gfg

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

// this is the brute force method .
//  class Solution {
//    public:
//      vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
//          // code here
//          vector<pair<int,int>> ans;
//          Node* temp=head;

//         while(temp){
//             Node* temp2=temp->next;
//             while(temp2){
//                 if(temp->data + temp2->data == target){
//                     ans.push_back({temp->data,temp2->data});
//                 }
//                 temp2=temp2->next;
//             }
//             temp=temp->next;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node *first = head;
        Node *tail = head;
        vector<pair<int, int>> ans;
        while (tail->next)
        {
            tail = tail->next;
        }

        while (first != tail && first->prev != tail)
        {
            if (tail->data + first->data == target)
            {
                ans.push_back({first->data, tail->data});
                tail = tail->prev;
                first = first->next;
            }
            else if (tail->data + first->data > target)
            {
                tail = tail->prev;
            }
            else
            {
                first = first->next;
            }
        }
        return ans;
    }
};