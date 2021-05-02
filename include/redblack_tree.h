#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

enum nodeColor
{ //algoritmada kullanılacağı renk tipleri(kırmızı ve siyah)
    RED,
    BLACK
};

struct rbNode
{ //algoritmada kullanacağı değişkenleri
    int data, color;
    struct rbNode *link[2];
};

// Red-Black Tree oluşturması
struct rbNode *createNode(int data);

// eleman ekleme fonksiyonu
struct rbNode *insertion(struct rbNode *root, int data);

// Silme fonksiyonu
struct rbNode *deletion(struct rbNode *root, int data);

//eleman yazma fonksiyonu
void inorderTraversal(struct rbNode *node);

#endif
