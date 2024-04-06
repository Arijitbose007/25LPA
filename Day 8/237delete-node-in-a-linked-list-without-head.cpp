class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* k = node->next;
        node->next = node->next->next;
        delete(k);
}
};