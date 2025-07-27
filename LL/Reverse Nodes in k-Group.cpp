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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* reversedHead = reverse(temp); 
            if (temp == head) {
                head = reversedHead;
            } else {
                prev->next = reversedHead;
            }

            prev = temp;  
            temp = nextNode; 
        }

        return head;
    }

   
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    
    ListNode* getKthNode(ListNode* head, int k) {
        while (head != nullptr && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }
};
