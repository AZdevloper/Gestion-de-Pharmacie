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
void Retour()
{
    int c;

    printf("\n 1:retur au menu\n  clic sur une boutton pour quitter le programme\n");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        main();
        break;

    default:
        printf("vous avez quitter le programme");
    }
}
void Menu()
{
    int n, code, qauntite;
    printf("---------1 : Ajouter un nouveau produit:\n");
    printf("---------2 : Ajouter plusieurs nouveaux produits \n");
    printf("---------3 : Lister tous les produits \n");
    printf("---------4 : Acheter produit \n");
    printf("---------5 : Rechercher un produits  \n");
    printf("---------6 : verifeir Etat du stock: \n");
    printf("---------7 :  Alimenter le stock:\n");
    printf("---------8 :  Supprimer les produits par :Code\n");
    printf("---------9:  Statistique de vente:\n");
    scanf(" %d", &n);
  
    switch (n)
    {
    case 1:
        ajouterUnProurduit();
        Retour();

        break;
    case 2:
        ajouterPlusieursProduits();
        Retour();
        break;
    case 3:
        listerTousProduits();
        Retour();
        break;
    case 4:
        printf("donnez code de produit : \n");
        scanf(" %d", &code);
        printf(" et quantite : ");
        scanf(" %d", &qauntite);
        acheterProduit(qauntite, code);
        Retour();
        break;
    case 5:
        recherchPrduit();
        Retour();
        break;
    case 6:
        etatStock();
        Retour();
        break;
    case 7:
        printf("donnez code de produit : \n");
        scanf(" %d", &code);
        printf(" et quantite : ");
        scanf(" %d", &qauntite);
        alimenterStock(code, qauntite);
        Retour();
        break;
    case 8:
        printf("donnez code de produit : \n");
        scanf(" %d", &code);
        supprimerProduits(code);
        Retour();
        break;
    case 9:
        statistiqueVente();
        Retour();
        break;

    default:
        break;
    }
}

int main()
{
    int n;

    printf("-------%c-%c-%c-%c--%c-Gestion de Pharmacie :-%c-%c-%c-%c-%c-----\n", 3, 3, 3, 3, 1, 1, 3, 3, 3, 3);

    Menu();
}