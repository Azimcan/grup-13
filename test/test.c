#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "ap_hash.h"
#include "xor_linked_list.h"
#include "bitonic_sort.h"
#include "redblack_tree.h"
#include "quickSort.h"

int main(void)
{
	srand(time(NULL));

	//////////////////////////////////////////////////////////////////////////////////////////////// AP HASH
	printf("AP HASH\n");

	char *data = "Ondokuz Mayıs Üniversitesi";
	unsigned int value = APHash(data);
	printf("input: %s\n", data);
	printf("output: %d\n", value);

	//////////////////////////////////////////////////////////////////////////////////////////////// XOR LINKED LIST
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

	//////////////////////////////////////////////////////////////////////////////////////////////// BITONIC SORT
	printf("\nBITONIC SORT\n");

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

	//////////////////////////////////////////////////////////////////////////////////////////////// RED-BLACK TREE
	printf("\nRED-BLACK TREE\n");

	struct rbNode *root = NULL; //ılk başta hıçbir eleman oluşmuyor o yüzden root null'a tanımlı;

	for (int i = 0; i < 10; i++)
	{
		root = insertion(root, i); //ekleme fonksiyonu kullanarak eleman eklenir
	}

	printf("ELemanlar: ");
	inorderTraversal(root); //inorder fonksiyonu kullanarak tüm elemanlar sıralı bir şekilde ekrana yazmak için
	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		root = deletion(root, i); //silme fonksiyonu kullanaraka eleman siliniyor
	}

	printf("ELemanlar: ");
	inorderTraversal(root);
	printf("\n");

	//////////////////////////////////////////////////////////////////////////////////////////////// QUICK SORT
	printf("\nQUICK SORT\n");

	int arr[10]; //siralanacak dizi
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 50;
	}

	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Dizinin ilk hali = ");
	printArray(arr, size);
	printf("\n");

	quickSort(arr, 0, (size - 1)); //siralama işlemi

	printf("Siralanmis dizi = ");
	printArray(arr, size);
	printf("\n");

	return 0;
}