struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create dummy node
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;  // remove node
            free(curr);               // free memory
            curr = prev->next;        // move forward
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
