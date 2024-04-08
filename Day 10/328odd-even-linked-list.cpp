class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* Odd = head;
        ListNode* Even = Odd->next;
        ListNode* Evenhead = Even;
        while(Even != NULL && Even->next != NULL)
        {
            Odd->next = Even->next;
            Odd = Odd->next;
            Even->next = Odd->next;
            Even = Even->next;
        }
            Odd -> next = Evenhead;
        return head;
    }
};