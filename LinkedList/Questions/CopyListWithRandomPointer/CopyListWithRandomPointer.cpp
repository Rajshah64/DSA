// leetcode problem number 138

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//        Node* temp=head;
//        map<Node*,Node*> mpp;

//        while(temp){
//         Node* t=new Node(temp->val);
//         mpp[temp]=t;
//         temp=temp->next;
//        }
//        temp=head;
//        while(temp){
//         Node* copyNode = mpp[temp];
//         copyNode->next= mpp[temp->next];
//         copyNode->random = mpp[temp->random];
//         temp=temp->next;
//        }
//         temp=head;
//        return mpp[temp];

//     }
// };

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // step 1 insert copy node between real ll
        Node *temp = head;
        while (temp)
        {
            Node *t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }

        // step 2 connect the random pointer for all the new nodes formed to the new nodes only .
        temp = head;
        while (temp)
        {
            temp->next->random = temp->random ? temp->random->next : nullptr;
            temp = temp->next->next;
        }

        // step 3 create separate linkedlist
        temp = head;
        Node *dummyHead = new Node(-1);
        Node *res = dummyHead;

        while (temp)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = res->next;
            temp = temp->next;
        }

        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};