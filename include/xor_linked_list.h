#ifndef XORLINKEDLIST_H
#define XORLINKEDLIST_H

struct Node
{
    int data;
    struct Node *xp; //Xor işlemi endeksli bağlantı pointerları
};

struct Node *XOR(struct Node *a, struct Node *b);
struct Node *addNode_xorList(struct Node **head, int value);
struct Node *deleteNode_xorList(struct Node **head);
void print_xorList(struct Node **head);

#endif