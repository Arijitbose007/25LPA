class Solution {
public:
    int multiplycarry(ListNode*head)
    {
        int t = 0;
        if(!head) return 0;
        t  = head->val * 2 + multiplycarry(head->next) ;
        head->val = t%10;
        return t/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int t = 0;
        t = multiplycarry(head);
        if(t) head = new ListNode(t ,head);
        return head;
    }
};