/***************************BITONIC SORT ALGORITMASI***************************

Bitonic sort algoritmasında temel olarak dizi 2'nin katları olarak alt parçalara bölünür 
ve indeks kontrolleriyle sıralama işlemi yapılır. Alt parçalara ayırma ve karşılaştırma 
işlemleri recursive yapı ile gerçekleştirilir. Yazılan kodda gruplara ayırma
işlemini özyineli olarak gerçekleştiren bitonicSort fonksiyonu ve gruplar için
sıralama işlemlerini gerçekleştiren merge fonksiyonu kullanılmıştır.

*******************************************************************************/
#include <stdio.h>
#include "bitonic_sort.h"

void merge(int array[], int iter, int groupSize, int control) //özyineli olarak oluşturulan grup bu fonksiyona aktarılır.
{
    int nGroupSize;

    if (groupSize > 1)
    {
        nGroupSize = groupSize / 2;

        int temp;
        for (int i = iter; i < iter + nGroupSize; i++)
        { //grup elemanlarının kıyaslandığı alan burasıdır.
            //grup boyutu yardımı ile bu işlem yapılır.
            //Örneğin grup 1,3,2,6 ise 1 ve 2, 3 ve 6 kontrol edilir.

            if (control == (array[i] > array[i + nGroupSize]))
            { //kontrol durumu onaylanırsa iki değer yer değiştirecek.

                temp = array[i];
                array[i] = array[i + nGroupSize];
                array[i + nGroupSize] = temp;
            }
        }

        merge(array, iter, nGroupSize, control); //indeksler için tekrar özyineli gönderim yapılacak.
        merge(array, iter + nGroupSize, nGroupSize, control);
    }
}

void bitonicSort(int array[], int iter, int groupSize, int control) //Gruplandırma işlemini yaparak merge fonksiyonuna gönderecek.
{
    int nGroupSize;

    if (groupSize > 1) //dizi en alt birimlere kadar gruplandırılacak.
    {
        nGroupSize = groupSize / 2;

        bitonicSort(array, iter, nGroupSize, 1); //özyineli yapılarla her grup için işlem gerçekleştirilecek.
        bitonicSort(array, iter + nGroupSize, nGroupSize, 0);

        merge(array, iter, groupSize, control); //parçalama işlemi biten grup indeks kontrolü ve sıralama için merge fonksiyonua gönderilecek.
    }
}
