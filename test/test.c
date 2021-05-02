#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "ap_hash.h"
#include "xor_linked_list.h"

int main(void)
{
	srand(time(NULL));

	//////////////// AP HASH
	printf("AP HASH\n");
	char *data = "Ondokuz Mayıs Üniversitesi";
	unsigned int value = APHash(data);
	printf("input: %s\n", data);
	printf("output: %d\n", value);

	//////////////// XOR LINKED LIST
	printf("\nXOR LINKED LIST\n");
	struct Node *head = NULL;
	addNode_xorList(&head, 10);
	addNode_xorList(&head, 20);
	addNode_xorList(&head, 30);
	addNode_xorList(&head, 40);

	print_xorList(&head);

	deleteNode_xorList(&head);

	print_xorList(&head);

	deleteNode_xorList(&head);

	print_xorList(&head);
	printf("\n");
}
