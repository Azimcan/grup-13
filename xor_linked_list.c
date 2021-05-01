#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node_t;

// "X" ve "y" nin xor'u döndürmek için yardımcı fonksiyon
Node_t *XOR(Node_t *x, Node_t *y)
{
    return (Node_t *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

//Listeyi ileri yönde yazdırmak için yardımcı fonksiyon
void traverse(Node_t *head)
{
    Node_t *curr = head;
    Node_t *prev = NULL;
    Node_t *next;

    while (curr != NULL)
    {
        printf("%d —> ", curr->data);

        next = XOR(prev, curr->link);

        prev = curr;
        curr = next;
    }

    printf("NULL");
}

// XOR linked listin  başına bir düğüm eklemek için yardımcı fonksiyon
void push(Node_t **head, int data)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    newNode->data = data;

    newNode->link = XOR(*head, NULL);

    if (*head)
    {
        (*head)->link = XOR(newNode, XOR((*head)->link, NULL));
    }

    *head = newNode;
}
