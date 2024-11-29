#include "ll.h"

#include <stdlib.h>

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->value = value;
    return node;
}

struct Node* getNext(struct Node* current) {
    if (current == NULL) {
        return NULL;
    }
    return current->next;
}

void append(struct Node* root, struct Node* toAppend) {
    root = getEnd(root);
    if (root != NULL) {
        root->next = toAppend;
    }
}

int hasNext(struct Node* current) {
    if (current == NULL) {
        return 0;
    }
    return current->next != NULL;
}

int getValue(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->value;
}

/**
 * If node is NULL, NULL is returned.
 * If the linked list is shorter that idx, NULL is returned.
 */
struct Node* getAt(struct Node* node, size_t idx) {
    for (int i = 0; i < idx && node != NULL; i++) {
        node = node->next;
    }
    return node;
}

int getValueAt(struct Node* node, size_t idx) {
    return getValue(getAt(node, idx));
}

size_t getLength(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int c = 1;
    while (hasNext(root)) {
        c++;
        root = getNext(root);
    }
    return c;
}

struct Node* getEnd(struct Node* root) {
    while (hasNext(root)) {
        root = getNext(root);
    }
    return root;
}

int removeAt(struct Node* root, size_t idx) {
    if (root == NULL) {
        return 0;
    }
    struct Node* prev = NULL;
    while (idx > 0) {
        if (!hasNext(root)) {  // check if list is long enough
            return 0;
        }
        prev = root;
        root = getNext(root);
        idx--;
    }
    if (hasNext(root)) {
        // restitch the list, when removing an element in the middle.
        // we copy the next element's data to the current element's data.
        // this preserves any pointers, in case we remove the first element.
        struct Node* next = getNext(root);
        *root = *next;
        free(next);
        return 1;
    }
    // when we remove the end of the list, we must unset the pointer of the
    // previous element
    if (prev != NULL) {
        prev->next = NULL;
    }
    free(root);
    return 1;
}

void delete(struct Node* root) {
    struct Node *current, *next;
    next = root;
    while (next != NULL) {
        current = next;
        next = getNext(current);
        free(current);
    }
}