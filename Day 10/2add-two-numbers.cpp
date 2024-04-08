class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *n1 = l1;
    ListNode *n2 = l2;
    ListNode *dummy = new ListNode(-1);
    ListNode* newListNode = dummy;
    int sum = 0 , carry = 0;
    while(n1 != NULL || n2 != NULL)
    {
        int sum = carry;
        if(n1)sum += n1->val;
        if(n2)sum += n2->val;
        newListNode->next = new ListNode(sum%10);
        carry = sum/10;
        newListNode = newListNode->next;
        if(n1)n1 =n1->next;
        if(n2)n2 = n2->next;
    }
    if (carry) {
        newListNode->next = new ListNode(carry);
    }
    return dummy->next;
    }
};