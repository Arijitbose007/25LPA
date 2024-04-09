class Solution {
public:
    ListNode* reverse(ListNode* node)
    {
        if(node == NULL || node->next == NULL)  return node;
        ListNode* reverseList =  reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return reverseList;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL ) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *second = reverse(slow->next);
        ListNode *temp = head;
        while (second != NULL) {
            if (temp->val != second->val) {
                // Not a palindrome
                return false;
            }
            temp = temp->next;
            second = second->next;
        }
        return true;
    }
};