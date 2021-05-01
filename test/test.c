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
	unsigned int value = APHash(data, 40);
	printf("input: %s\n", data);
	printf("output: %d\n", value);

	//////////////// XOR LINKED LIST
	printf("\nXOR LINKED LIST\n");
	// Size
	int n = 5;

	struct Node *head = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		push(&head, rand() % 20);
	}

	traverse(head);
	printf("\n");
}
