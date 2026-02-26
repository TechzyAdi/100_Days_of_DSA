// Definition of Node
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Definition of MyLinkedList
typedef struct {
    Node* head;
    int size;
} MyLinkedList;


// Constructor
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}


// Get value at index
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp->val;
}


// Add at head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}


// Add at tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if(obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* temp = obj->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    obj->size++;
}


// Add at index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index < 0 || index > obj->size)
        return;

    if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* temp = obj->head;
    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}


// Delete at index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    if(index < 0 || index >= obj->size)
        return;

    Node* temp = obj->head;

    if(index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
    }

    obj->size--;
}


// Free memory
void myLinkedListFree(MyLinkedList* obj) {
    Node* temp = obj->head;
    while(temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(obj);
}
