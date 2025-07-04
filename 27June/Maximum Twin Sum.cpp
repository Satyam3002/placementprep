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
    int pairSum(ListNode* head) {
        ListNode* secondHalf;
        ListNode* firstHalf = splitInHalf(head, secondHalf);
        ListNode* Reverse = reverse(secondHalf);
        int maxSum = 0;
        while(firstHalf != nullptr && Reverse != nullptr) {
            maxSum = max(maxSum, firstHalf->val + Reverse->val);
            firstHalf = firstHalf->next;
            Reverse = Reverse->next;
        }
        return maxSum;



    }
    private:


    ListNode* splitInHalf(ListNode* head, ListNode*& secondHalf) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    secondHalf = slow->next;
    slow->next = nullptr;

    return head;
}
  
    ListNode* reverse(ListNode* head) {


        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
