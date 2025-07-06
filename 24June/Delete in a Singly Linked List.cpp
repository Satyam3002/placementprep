/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if (x==1) {
            Node* temp = head;
            head = head ->  next;
            temp ->next = NULL;
            delete temp;
        }
        
        else {
            Node* prev = NULL;
            Node* curr =  head;
            while (x!= 1) {
                x--;
                prev = curr;
                curr =  curr -> next;
            }
             prev->next = curr->next;
             curr->next = NULL;
             delete curr;
        }
         return head;
    }
};