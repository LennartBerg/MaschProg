#include <stdio.h>
#include <stdlib.h>

#include "ll.h"
/*
Implementieren Sie alle in der Datei ll.h beschriebenen Funktionen.
Damit realisieren Sie eine einfach verkettete Liste.

Kompilieren und testen Sie Ihre Bibliothek. Laden Sie dann die ll.c im StudIP hoch.
*/

#define BUFFER 256

char* printList(struct Node* list, char* buffer) {
    struct Node* root = list;
    buffer += sprintf(buffer, "List: [%d", getValue(list));

    while (hasNext(list)) {
        list = getNext(list);
        buffer += sprintf(buffer, ",%d", getValue(list));
    }
    buffer += sprintf(buffer, "] of length %u\n", getLength(root));
    return buffer;
}

int main(void) {
    char buffer[BUFFER];
    char* idx = buffer;

    /* create root node */
    struct Node* root = createNode(0);

    /* insert 31 elements */
    for (int i = 1; i < 32; i++) {
        append(root, createNode(i));
    }

    idx = printList(root, buffer);

    /* Katastrophe! Wahrscheinlich langsam. Warum? */
    for (size_t i = getLength(root) - 1; i-- > 0;) {
        if (getValueAt(root, i) % 2 == 0) {
            removeAt(root, i);
        }
    }
    idx += sprintf(idx, "Removed every even value from list:\n");
    printList(root, idx);
    delete (root);

    puts(buffer);
    return 0;
}