#include <string.h>

unsigned int APHash(char *str)
{
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;

    // Girdinin her bir elemani aphash islemine tutularak dongu ilerler
    // en son durumda girdinin ozet(hash) durumu olusur
    for (i = 0; i < strlen(str); str++, i++)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) : (~((hash << 11) + ((*str) ^ (hash >> 5))));
    }

    return hash;
}