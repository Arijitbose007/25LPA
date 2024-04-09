class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *fast = head;
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *slow = temp;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};