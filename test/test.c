#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "ap_hash.h"
#include "xor_linked_list.h"
#include "bitonic_sort.h"

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
	printf("\nXOR LINKED LIST");

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

	//////////////// Bitonic Sort
	printf("\nBitonic Sort\n");

	int array[] = {5, 10, 27, 2, 18, 15, 7, 4, 14, 6, 1, 11, 19, 11, 23, 45};

	int arraySize = sizeof(array) / sizeof(array[0]); //dizinin boyutunu alıyoruz.

	printf("Olusturulan dizi = ");
	for (int i = 0; i < arraySize; i++)
		printf("%d ", array[i]);
	printf("\n");
	bitonicSort(array, 0, arraySize, 1); //bitonic Sıralaması

	printf("Siralanmis dizi = "); //sıralanmış dizi
	for (int i = 0; i < arraySize; i++)
		printf("%d ", array[i]);
	printf("\n");
}