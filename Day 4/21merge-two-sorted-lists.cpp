class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *head;
        if(list1->val <= list2->val)  {head = list1; list1 = list1 -> next;}
        else {head = list2; list2 = list2 -> next;}
        ListNode *cur = head;
        while(list1 && list2)
        {
            if(list1->val >= list2->val) {cur->next = list2; list2 = list2 -> next;}
            else {cur -> next = list1; list1 = list1 -> next;}
            cur = cur->next;
        }

        if(!list1) cur -> next = list2;
        else if(!list2) cur -> next = list1;
        return head;
    }
};