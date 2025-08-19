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

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root)
    {
        // Your code here
        vector<int> arr;
        Node *temp = root;
        while (temp)
        {
            Node *temp2 = temp;
            while (temp2)
            {
                arr.push_back(temp2->data);
                temp2 = temp2->bottom;
            }
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        Node *newHead = new Node(arr[0]);
        temp = newHead;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *t = new Node(arr[i]);
            temp->bottom = t;
            temp = temp->bottom;
        }
        return newHead;
    }
};