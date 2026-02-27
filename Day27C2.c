class Solution
{
public:
    void removeLoop(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return;

        Node *slow = head, *fast = head;

        // Detect loop using Floyd Cycle
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // If no loop
        if(fast == NULL || fast->next == NULL)
            return;

        // Move slow to head
        slow = head;

        // If loop starts at head
        if(slow == fast)
        {
            while(fast->next != slow)
                fast = fast->next;
        }
        else
        {
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Remove loop
        fast->next = NULL;
    }
};
