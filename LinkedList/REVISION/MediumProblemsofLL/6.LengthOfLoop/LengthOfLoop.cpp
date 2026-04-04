// solved on gfg

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            // Loop detected → count length
            int cnt = 1;
            Node* temp = slow->next;

            while(temp != slow){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
    }
    return 0; // No loop
}