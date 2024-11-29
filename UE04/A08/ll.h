#include <stdlib.h>

/*Node element, which is part of a list*/
struct Node {
    int value;
    struct Node* next;
};

/*creates a node in dynamic memory; returns the adress of this node*/
struct Node* createNode(int value);

/*returs the following list element*/
struct Node* getNext(struct Node* current);

/*appends a referenced element to the list, of which is root part of */
void append(struct Node* root, struct Node* toAppend);

/*returns 1, if current is not the last element of the list, otherwise 0*/
int hasNext(struct Node* current);

/*returns the associated value of an list element*/
int getValue(struct Node* node);

/*returns a reference to the element of given index in the list beginning with root*/
struct Node* getAt(struct Node* root, size_t idx);

/*returns the value of the element of given index in the list beginning with root*/
int getValueAt(struct Node* root, size_t idx);

/*returns the length of the list beginning with root*/
size_t getLength(struct Node* root);

/*returns a reference to the last element of the list beginning with root*/
struct Node* getEnd(struct Node* root);

/*removes the element at given index of the list beginning with root.
  returns 0, if allocated memory has beem freed, and 1, otherwise*/
int removeAt(struct Node* root, size_t idx);

/*deletes the hole list beginning with root and frees allocaded memory*/
void delete(struct Node* root);