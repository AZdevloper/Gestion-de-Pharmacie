#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
// struct produit
typedef struct produit
{
    char nom[20];
    int code;
    float prix;
    float prixTTC;
    int quantite;

} produit;
produit Prdt[100];

int nomberDesProduit = 0;
int main()
{
    int n;

    printf("-------%c-%c-%c-%c--%c-Gestion de Pharmacie :-%c-%c-%c-%c-%c-----\n", 3, 3, 3, 3, 1, 1, 3, 3, 3, 3);

    Menu();
}