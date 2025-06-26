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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *tail = head;
        int len = 0;
        while (tail != NULL)
        {
            len++;
            tail = tail->next;
        }
        if (k % len == 0)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < k % len; i++)
        {
            fast = fast->next;
        }
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *front = slow->next;
        slow->next = NULL;
        if (front)
            fast->next = head;
        head = front;
        return head;
    }
};