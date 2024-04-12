class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->next == NULL) break;
            if(temp->val == temp->next->val)
            {
                ListNode* extra = temp->next;
                temp->next = temp->next->next;
                delete(extra);
                continue;
            }
            
           temp = temp->next;     
        }
        
       
        return head;
    }
};