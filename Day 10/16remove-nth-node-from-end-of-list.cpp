class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *temp2 = head;
         while(n != 0)
            {
                temp = temp->next;
                n--;
            }
        if(temp == NULL) return head->next;
        while(temp->next != NULL)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        ListNode *delNode = temp2->next;
        temp2->next = temp2->next->next;
        delete(delNode);
        return head;
    }
};