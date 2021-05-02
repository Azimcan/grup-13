/*************************************************QUICK SORT ALGORITMASI*****************************************************

  Quick Sort, siralanmasi hedeflenen bir diziyi bol ve yonet mantigi ile daha kucuk iki parcaya ayirip 
olusan parcalari kendi icinde kucukten buyuge siralayan bir algoritmadir.

  Quick Sort algoritmasi siralanacak dizide ilk olarak herhangi bir elamani pivot olarak secer. Secilen bu pivota gore 
dizi, pivot elemanindan kucuk olanlar sol tarafta ve buyuk olanlar sag tarafta olacak sekilde kümelendirilir.Bu islem 
ozyineli olarak devam eder. Bu sekilde algoritma; eleman sayisi sifir olan bir alt diziye ulasincaya kadar bol ve yonet 
islemini uygular. Eleman sayisi sifir olan alt diziye ulasildiğinda dizi sıralanmis hale gelir. 

****************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Iki elemanin yer degistirmesi icin kullanilan fonksiyonudur.
void swapIndex(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Partition fonksiyonunda ilk once pivot elemanı secilir(son eleman). Daha sonra pivot elemani 
sıralanmis dizideki kendi konumuna yerlestirilir. Pivottan kucuk elemanlar sol tarafa,buyukler ise
sag tarafa yerlestirilir. */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];                // pivot degeri aliniyor(son eleman).
    int i = (low - 1);                    //counter degiskenlerden ilki. For dongusunde kullanilacak.
    for (int j = low; j <= high - 1; j++) //j ise ikinci counter değişkendir.
    {

        if (arr[j] < pivot) // İlgili eleman pivottan daha kucuk ise;
        {
            i++;
            swapIndex(&arr[i], &arr[j]); //Counterlar aracılığıyla indeks degisim islemi yapilir.
        }
    }
    swapIndex(&arr[i + 1], &arr[high]); // For dongusu sonunda counterin bir ilerisine pivot yerlestirilir.
    return (i + 1);
}

void quickSort(int arr[], int low, int high) // QuickSort işlemini gerçekleştiren ana fonksiyondur.
{
    if (low < high) // low başlangıç indeksini,high ise bitiş indeksini ifade etmektedir.
    {

        int p = partition(arr, low, high); // p değişkeni kümeleme indeksini ifade eder.

        /* Dizi Degerleri kumelenmeden once ve 
  kumelenmeden sonra ayri ayri siralanir. */
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void printArray(int array[], int arraySize)
{ //diziyi bastırmak icin kullanılacak fonksiyondur.

    for (int i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
}
