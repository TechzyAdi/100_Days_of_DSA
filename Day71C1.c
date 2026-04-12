#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];

// Initialize table
void initialize(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert function
void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
    }

    printf("Hash Table is FULL!\n");
}

// Search function
void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == -1) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

// Display table
void display(int m) {
    printf("\nCurrent Hash Table:\n");
    for (int i = 0; i < m; i++) {
        if (table[i] == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, table[i]);
    }
}

int main() {
    int m, q;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    initialize(m);

    char op[10];
    int key;

    printf("\nOperations:\n");
    printf("Use INSERT <key> or SEARCH <key>\n\n");

    for (int i = 0; i < q; i++) {
        printf("Operation %d: ", i + 1);
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        } 
        else {
            printf("Invalid operation!\n");
        }
    }

    display(m);

    return 0;
}
