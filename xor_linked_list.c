/******************************************************************************
                            XOR LINKED LIST HAKKINDA
XOR yapısında bağlantılar için bitsel XOR(Özel Veya) işlemleri yapılır. Burada
temel amaç çift yönlü bağlantıların indirgenmesi ve hafıza kullanımının azaltılmasıdır.
Temel olarak, bir önceki düğüm ve bir sonraki düğümün adresleri XOR işlemine tutulur ve oluşan değer
ilgili düğümün pointerına atanır. 
Liste üzerinde yapılacak gezinme işlemine göre pointer değerleri tekrar XOR işlemine tutulur. 
Örneğin bir düğümün önceki düğüm adresi 100 ve sonraki adresi 300 olsun. Düğümün pointerı (100^300)
adresini tutacaktır. Eğer bu pointer ile bir önceki adresi tekrar XOR yaparsak 100^(100^300) = 300 olur.
Bu şekilde ilgili düğümden sonra gelen düğümün adresine erişilebilir.
*******************************************************************************/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *xp; //Xor işlemi endeksli bağlantı pointerları
};

struct Node *XOR(struct Node *a, struct Node *b) //XOR işleminin yapıldığı fonksiyon.
{
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b)); //Gönderilen adresler işleme giriyor ve sonuç döndürülüyor.
} // uintptr işaretçi depolayabilen tamsayı türüdür.

struct Node *addNode_xorList(struct Node **head, int value) //Düğüm ekleme fonksiyonu
{
    if (*head == NULL)
    { // Eğer henüz bir düğüm oluşturulmamışsa bu koşula girecektir.(ilklendirme)

        struct Node *node = (struct Node *)malloc(sizeof(struct Node)); //dugum olusturulur.

        node->data = value; //veri atanır.

        node->xp = XOR(NULL, NULL); //Pointer için XOR yapılır.
                                    //İlk değer olduğu için kendinden önceki düğüm yerine NULL girildi.
                                    //Kendinden sonra bir düğüm olmadığı içinde NULL girildi.
        *head = node;               //Düğüm head pointerına atandı. En sonda Head return edilecek.
    }

    else
    { // Eğer önceden oluşturulmuş bir düğüm varsa bu koşula girecektir.

        struct Node *iter = *head; //iter oluşturuldu ve head'in tuttuğu adres atandı.(gezme işlemi için)

        struct Node *node = (struct Node *)malloc(sizeof(struct Node));

        node->data = value;         //veri atanır.
        node->xp = XOR(NULL, iter); //eklenen yeni düğüm için XOR işlemi (önceki düğüm adresi ^ sonraki düğümün adresi(NULL))

        iter->xp = XOR(node, XOR(NULL, iter->xp)); /* Bir dügüm eklendiği zaman pointerı önceki ve sonraki düğümlerin XOR sonucunu tutar.
                                                        Düğümler en sona eklendiği için sonraki değerleri NULL yapılır. Bir sonraki düğüm
                                                        ekleme işleminde NULL değerin değiştirilmesi ve bir önceki düğüme yeni düğüm 
                                                        adresinin eklenmesi gerekir. Burada bir önceki düğümün pointerı için bu güncelleme yapılmaktadır.*/

        *head = node; //Eklenen düğüm head'e atanıyor.
    }
    return *head;
}

struct Node *deleteNode_xorList(struct Node **head) //Listeden en son eklenen elemanı silme islemi
{

    if (*head == NULL) // Listede düğüm yoksa bu koşula girecektir.
        printf("Silinecek oge bulunamadi (Liste Bos).");
    else
    {

        struct Node *iter = *head; //head içeriği iter'e aktarılıyor.

        struct Node *prev = NULL; //prev ile silinecek düğümden bir önceki düğüme, head'i bağlama işlemi yapılacaktır.

        prev = XOR(iter->xp, NULL); //Listedeki son eleman için xp değeri = (bir önceki düğüm adresi ^ NULL) şeklindedir.
                                    //O halde "XOR((bir önceki düğüm adresi ^ NULL)^NULL) = bir önceki düğüm adresi" olur.

        prev->xp = XOR(iter, prev->xp); //Son eleman silindiği için bir önceki düğümün pointerındaki adres güncelleniyor.

        *head = prev; //head bir önceki düğümü tutmaya başladı. Artık son düğüm silinebilir.
        free(iter);   //iter yardımı ile son düğüm siliniyor.
    }
    return *head;
}

void print_xorList(struct Node **head)
{ // Düğümleri bastıran fonksiyon

    struct Node *iter = *head; //head(son düğüm adresi) iter'e atanıyor. İter ile gezinme işlemi yapılacak.

    struct Node *prev = NULL; //prev ile bastırılan son düğümün adresi tutulacak.

    struct Node *next; // next ile sıradaki düğümün adresi tutulacak.

    printf("\n Liste elemanlari = ");
    while (iter != NULL)
    { //iter NULL olana kadar işlem devam edecek.

        printf("%d ", iter->data); //ilgili düğümün değeri bastırıldı.

        next = XOR(prev, iter->xp); /* İlgili düğümden sonraki düğüm adresi next'e atanıyor. 
                                      XOR(bastırılan son düğüm adresi^(bastırılan son düğüm adresi ^ bir sonraki düğümün adresi))
                                      XOR = bir sonraki düğümün adresi */

        prev = iter; //Bastırılan son düğüm preve atanacak.

        iter = next; //Sıradaki düğüm iter'e atanacak.
    }
}
