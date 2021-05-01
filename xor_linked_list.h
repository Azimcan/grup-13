struct Node
{
    int data;
    struct Node *link;
};

struct Node *XOR(struct Node *x, struct Node *y);

void traverse(struct Node *head);

void push(struct Node **head, int data);
