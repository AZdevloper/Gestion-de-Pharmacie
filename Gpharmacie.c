#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
typedef struct produitAchet
{
    float prixTTC;
    int prix;
    char dateAchat[100];

} prdacheter;

prdacheter PrdtAcheter[100];
int countPrdtAchter = 0;

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

void ajouterUnProurduit()
{

    printf("---------------------\n");
    printf(" donnez nom de produit :");
    scanf("   %s", &Prdt[nomberDesProduit].nom);

    printf(" donnez le code de produit (!Unique ) :");
    scanf("   %d", &Prdt[nomberDesProduit].code);

    printf(" donnez prix de produit :");
    scanf("   %f", &Prdt[nomberDesProduit].prix);
    Prdt[nomberDesProduit].prixTTC = Prdt[nomberDesProduit].prix + 0.15 * Prdt[nomberDesProduit].prix;

    printf(" donnez la quantite :");
    scanf("   %d", &Prdt[nomberDesProduit].quantite);

    nomberDesProduit++;
}

void ajouterPlusieursProduits()
{

    int n;
    printf(" donnez nomber des produit:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ajouterUnProurduit();
    }
}

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

void ordreAlphabetiqueCroissant()
{

    produit t;
    int i, k;

    for (i = 0; i < nomberDesProduit; i++)
    {
        for (k = 0; k <= nomberDesProduit - i - 1; k++)
        {
            if (strcmp(Prdt[k].nom, Prdt[k + 1].nom) > 0)

            {
                t = Prdt[k];

                Prdt[k] = Prdt[k + 1];

                Prdt[k + 1] = t;
            }
        }
    }
    printf("les medecament son :");

    for (int f = 1; f <= nomberDesProduit; f++)
    {

        printf("\n nom : %s   prix : %f   code: % d   quantite : %d prixTTC : %f  \n ", Prdt[f].nom, Prdt[f].prix, Prdt[f].code, Prdt[f].quantite, Prdt[f].prixTTC);
    }
}

void orderDecroissantPrix()
{

    produit t;
    int i, k;

    for (i = 0; i < nomberDesProduit; i++)
    {
        for (k = 0; k <= nomberDesProduit - i - 1; k++)
        {
            if (Prdt[k].prix < Prdt[k + 1].prix)

            {
                t = Prdt[k];

                Prdt[k] = Prdt[k + 1];

                Prdt[k + 1] = t;
            }
        }
    }

    printf("les medecament son :");
    for (int f = 0; f < nomberDesProduit; f++)
    {

        printf("\n nom : %s   prix : %f   code: %d   quantite : %d prixTTC : %f   ", Prdt[f].nom, Prdt[f].prix, Prdt[f].code, Prdt[f].quantite, Prdt[f].prixTTC);
    }
}

void listerTousProduits()
{
    int c;
    printf(" entrez -1- pour lister tous les produits selon l ordre alphabétique  croissant du nom.: \n");
    printf(" entrez -2- pour lister tous les produits selon l ordre  décroissant du prix. :\n   ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        ordreAlphabetiqueCroissant();
        break;

    case 2:
        orderDecroissantPrix();
        break;

    default:
        break;
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