class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head and head->next){
            ListNode* newHead = removeNodes(head->next);
            if(newHead->val > head->val)return newHead;
            head->next = newHead;
        }
        return head;
    }
};