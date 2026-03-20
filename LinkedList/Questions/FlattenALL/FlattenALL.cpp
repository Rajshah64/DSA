// this question was solved on gfg

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

// class Solution {
//   public:
//     // Function which returns the  root of the flattened linked list.
//     Node *flatten(Node *root) {
//         // Your code here
//         vector<int> arr;
//         Node* temp=root;
//         while(temp){
//             Node* temp2= temp;
//             while(temp2){
//                 arr.push_back(temp2->data);
//                 temp2=temp2->bottom;
//             }
//             temp=temp->next;
//         }
//         sort(arr.begin(), arr.end());
//         Node* newHead= new Node(arr[0]);
//         temp=newHead;
//         for(int i=1;i<arr.size();i++){
//             Node* t=new Node(arr[i]);
//             temp->bottom =t;
//             temp=temp->bottom;
//         }
//         return newHead;
//     }
// };

// this is not so optimal cause we use extra space as well as a lot of time .

class Solution
{
private:
    Node *merge(Node *list1, Node *list2)
    {
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else
            {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = nullptr;
        }
        if (list1)
            res->bottom = list1;
        else
            res->bottom = list2;
        if (dummy->bottom)
            dummy->bottom->next = nullptr;
        return dummy->bottom;
    }

public:
    Node *flatten(Node *root)
    {
        if (!root || !root->next)
        {
            return root;
        }
        Node *mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        return root;
    }
};

class Solution
{
private:
    Node *merge(Node *list1, Node *list2)
    {
        Node *dummy = new Node(-1);
        Node *res = dummy;

        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                res->bottom = list1;
                list1 = list1->bottom;
            }
            else
            {
                res->bottom = list2;
                list2 = list2->bottom;
            }
            res = res->bottom;
        }

        if (list1)
            res->bottom = list1;
        else
            res->bottom = list2;

        return dummy->bottom;
    }

public:
    Node *flatten(Node *root)
    {
        if (!root || !root->next)
        {
            return root;
        }

        Node *mergedHead = flatten(root->next);

        root = merge(root, mergedHead);
        return root;
    }
};