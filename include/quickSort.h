#ifndef QUICKSORT_H
#define QUICKSORT_H

// Iki elemanin yer degistirmesi icin kullanilan fonksiyonudur.
void swapIndex(int *a, int *b);

/* Partition fonksiyonunda ilk once pivot elemanı secilir(son eleman). Daha sonra pivot elemani 
sıralanmis dizideki kendi konumuna yerlestirilir. Pivottan kucuk elemanlar sol tarafa,buyukler ise
sag tarafa yerlestirilir. */
int partition(int arr[], int low, int high);

// QuickSort işlemini gerçekleştiren ana fonksiyondur.
void quickSort(int arr[], int low, int high);

//diziyi bastırmak icin kullanılacak fonksiyondur.
void printArray(int array[], int arraySize);

#endif