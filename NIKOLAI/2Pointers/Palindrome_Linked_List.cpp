
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        fast = head;
        while (slow) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        return prev;
    }
};
