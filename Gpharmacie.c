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

void acheterProduit(int quantite, int code)
{
    int s = 0, now, i;

    for (i = 0; i < quantite; i++)
    {
        if (Prdt[i].code == code)
        {
            Prdt[i].quantite -= quantite;
            break;
        }
    }
    time(&now);
    strcpy(PrdtAcheter[countPrdtAchter].dateAchat, ctime(&now));

    PrdtAcheter[countPrdtAchter].prixTTC = Prdt[i].prixTTC;

    PrdtAcheter[countPrdtAchter].prix = Prdt[i].prix;

    ++countPrdtAchter;
}



void rechercherProduitsCode(int code)
{

    int s;
    for (int i = 0; i < nomberDesProduit; i++)
    {
        if (Prdt[i].code == code)
        {
            printf("\n nom : %s   prix : %f   code: %d   quantite : %d prixTTC : %f   ", Prdt[i].nom, Prdt[i].prix, Prdt[i].code, Prdt[i].quantite, Prdt[i].prixTTC);
        }
        else
            s++;
    }
    if (s == nomberDesProduit)
        printf("ce code ne ce trouve pas donne le stock ? ");
}


void rechercherProduitsquantite(int quan)
{
    int s=0, q;
    for (int i = 0; i < nomberDesProduit; i++)
    {
        if (Prdt[i].quantite == quan)
        {
            printf("\n nom : %s   prix : %f   code: %d   quantite : %d prixTTC : %f   ", Prdt[i].nom, Prdt[i].prix, Prdt[i].code, Prdt[i].quantite, Prdt[i].prixTTC);
        }
        else
            s++;
    }
    if (s == nomberDesProduit)
        printf("cette quantite ne ce trouve pas donne le stock ? ");
}
void recherchPrduit()
{
    int c, code, quan;
    printf("  recherche produit par code taper 1 : \n  recherche produit par quantite taper 2 :\n  ");
    scanf(" %d", &c);
    switch (c)
    {
    case 1:
        printf("donnez le code de produit :\n");
        scanf("  %d", &code);
        rechercherProduitsCode(code);

        break;
    case 2:
        printf("donnez la quantite de produit :\n");
        scanf("  %d", &quan);
        rechercherProduitsquantite(quan);

    default:
        break;
    }
}

void etatStock()
{  int s=0;
    for (int i = 0; i < nomberDesProduit; i++)
    {
        if (Prdt[i].quantite < 3)
        {
            s++;
            printf("\n nom : %s   prix : %f DH  code: %d   quantite : %d prixTTC : %f DH  ", Prdt[i].nom, Prdt[i].prix, Prdt[i].code, Prdt[i].quantite, Prdt[i].prixTTC);
        }

    }
    if(s == 0)
       printf("pas de manque dans le stock");

}

void alimenterStock(int code, int quantite)
{

    int s;
    for (int i = 0; i < nomberDesProduit; i++)
    {
        if (Prdt[i].code == code)
        {

            Prdt[i].quantite = quantite;
            printf(" la quantite est alimenter  ");
        }
        else
            s++;
    }
    if (s == nomberDesProduit)
    {
        printf("ce code ne ce trouve pas donne le stock ? \n");
        printf("  tu peu ajouter comme un neuvaux produit ");
    }
}

void supprimerProduits(int code)
{
    printf("avant supremer :%d", nomberDesProduit);
    for (int f = 0; f < nomberDesProduit; f++)
    {

        printf("\n nom : %s   prix : %f   code: %d   quantite : %d prixTTC : %f  \n ", Prdt[f].nom, Prdt[f].prix, Prdt[f].code, Prdt[f].quantite, Prdt[f].prixTTC);
    }

    int s = 0;

    for (int i = 0; i < nomberDesProduit; i++)
    {
        if (Prdt[i].code == code)
        {
            for (int j = i; j < nomberDesProduit; j++)
            {
                Prdt[j] = Prdt[j + 1];
            }
            --nomberDesProduit;
        }
        else
            ++s;
    }
    if (s == nomberDesProduit)
    {
        printf(" pas de produit avec ce code  \n");
    }

    printf("aprer supremer :%d \n", nomberDesProduit);

    for (int f = 0; f < nomberDesProduit; f++)
    {

        printf("\n nom : %s   prix : %f   code: %d   quantite : %d prixTTC : %f  \n ", Prdt[f].nom, Prdt[f].prix, Prdt[f].code, Prdt[f].quantite, Prdt[f].prixTTC);
    }
}
void totalPrixProduits()
{
    float s = 0;
    for (int i = 0; i < countPrdtAchter; i++)
    {
        s += PrdtAcheter[i].prix;
    }
    printf("Totale des prix des produit est %f DH ", s);
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