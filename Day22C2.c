struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;  // store next node
        curr->next = prev;      // reverse link
        prev = curr;            // move prev forward
        curr = nextNode;        // move curr forward
    }

    return prev;  // new head
}
