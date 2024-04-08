class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            st.push(temp);
            temp = temp->next;
        }
        temp = head;
        int counter = st.size()/2;
        while(counter--)
        {
            ListNode *topNode = st.top();
            st.pop();
            ListNode *temp2 = temp->next;
            temp->next = topNode;
            topNode->next = temp2;
            temp = temp2;
        }
    temp->next = NULL;    
    return ;

    }
};