class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL , *nextNode, *temp = head;
        while(temp){
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }
        head = prevNode;
        return head;
    }
};
