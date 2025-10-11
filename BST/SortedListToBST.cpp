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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {

        return Build(head, nullptr);
    }

    TreeNode *Build(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return nullptr;
        ListNode *mid = middleNode(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        root->left = Build(head, mid);
        root->right = Build(mid->next, tail);
        return root;
    }

    ListNode *middleNode(ListNode *head, ListNode *tail)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail)
        {
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }
};