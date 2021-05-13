#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def_fonctions.h"

date saisie_date()
{
    date d;

    printf("\n\ndonner le jour de la naissance de l'employ%c %c ajouter (format jj):\n ", 130, 133);
    gets(d.jour);

    printf("\n\ndonner le mois de la naissance de l'employ%c %c ajouter (format mm):\n ", 130, 133);
    gets(d.mois);
    
    printf("\n\ndonner l'ann%ce de la naissance de l'employ%c %c ajouter (format aaaa):\n ", 130, 130, 133);
    gets(d.annee);

    return d;
}

adresse saisie_adresse(){
    adresse a;

    printf("\n\ndonner le gouvernorat o%c habite l'employ%c %c ajouter:\n ", 151, 130, 133);
    gets(a.gouvernorat);

    printf("\n\ndonner la ville\n");
    gets(a.ville);

    printf("\n\ndonner la rue\n");
    gets(a.rue);

    printf("\n\ndonner le code postal\n");
    gets(a.code_postal);

    return a;
}

void ajouter_employe(employe tab[maximum], int *n)
{
    employe x;

    printf("\n\ndonner l'identifiant de l'employ%c \n", 130);
    gets(x.identifiant);
    
    printf("\n\ndonner le numero de son CIN\n");
    gets(x.n_cin);

    printf("\n\ndonner son nom\n");
    gets(x.nom);

    printf("\n\ndonner son pr%cnom\n", 130);
    gets(x.prenom);

    printf("\n\ndonner son sexe\n");
    gets(x.sexe);

    x.date_de_naissance = saisie_date();
    x.adr = saisie_adresse();
    
    printf("\n\ndonner son num%cro de tel\n", 130);
    gets(x.tel);

    printf("\n\ndonner son %ctat civil\n", 130);
    gets(x.etat_civil);

    printf("\n\ndonner le nombre de ses enfants\n");
    scanf("%d", &x.nombre_enfants);
    getchar();
    
    tab[*n] = x;
    (*n)++;
    printf(" \n \n employ%c ajout%c avec succ%css ! ", 130, 130, 138); 
}

void afficher_employe(employe x, employe tab[maximum], int n)
{
    int i = 0, ctr = 0;

    while (i < n) {
        if (strcmp(tab[i].n_cin, x.n_cin) == 0) {
            printf("identifiant: %s\n", tab[i].identifiant);
            printf("CIN: %s\n", tab[i].n_cin);
            printf("nom: %s\n", tab[i].nom);
            printf("pr%cnom: %s\n", 130, tab[i].prenom);
            printf("sexe: %s\n", tab[i].sexe);
            printf("date de naissance: %s/%s/%s\n", tab[i].date_de_naissance.jour, tab[i].date_de_naissance.mois,
                                                                tab[i].date_de_naissance.annee);
            printf("adresse: %s, %s, %s, %s\n", tab[i].adr.gouvernorat, tab[i].adr.ville, tab[i].adr.rue, tab[i].adr.code_postal);
            printf("tel: %s\n", tab[i].tel);
            printf("etat civil: %s\n", tab[i].etat_civil);
            printf("nombre d'enfants: %d\n", tab[i].nombre_enfants);
            ctr = 1;
            break;
        }
        i++;
    }
    if(ctr == 0) printf("l'employe ne travaille pas dans l'entreprise");

}
void afficher_tous_employes(employe tab[maximum], int n)
{
    for (int i = 0; i < n; i++) {
        printf("identifiant: %s\n", tab[i].identifiant);
            printf("CIN: %s\n", tab[i].n_cin);
            printf("nom: %s\n", tab[i].nom);
            printf("pr%cnom: %s\n", 130, tab[i].prenom);
            printf("sexe: %s\n", tab[i].sexe);
            printf("date de naissance: %s/%s/%s\n", tab[i].date_de_naissance.jour, tab[i].date_de_naissance.mois,
                                                                tab[i].date_de_naissance.annee);
            printf("adresse: %s, %s, %s, %s\n", tab[i].adr.gouvernorat, tab[i].adr.ville, tab[i].adr.rue, tab[i].adr.code_postal);
            printf("tel: %s\n", tab[i].tel);
            printf("etat civil: %s\n", tab[i].etat_civil);
            printf("nombre d'enfants: %d\n", tab[i].nombre_enfants);
            printf("\n******************************************\n");
    }
}

void supprimer_employe(employe x, employe tab[maximum], int *n){
    int i = 0, ctr = 0;
    while (i < *n) {
        if (strcmp(tab[i].n_cin, x.n_cin) == 0){
            ctr = 1;
            printf("l'employ%c est supprim%c", 130, 130);
            break;
        }
        i++;
    }
    if (ctr == 1) {
        for (int j = i; j < *n; ++j) tab[j] = tab[j+1];
        (*n)--;
    }
    else printf("l'employ%c ne travaille pas dans l'entreprise", 130);
}

void modifier_employe(employe x, employe tab[maximum], int n)
{
    int i = 0, ctr = 0;
    while (i < n) {
        if (strcmp(tab[i].n_cin, x.n_cin) == 0) {

            printf("\n\ndonner le nouveau identifiant\n");
            gets(tab[i].identifiant);

            printf("\n\ndonner le nouveau num%cro de la CIN\n", 130);
            gets(tab[i].n_cin);

            printf("\n\ndonner le nouveau nom\n");
            gets(tab[i].nom);

            printf("\n\ndonner le nouveau pr%cnom\n", 130);
            gets(tab[i].prenom);

            printf("\n\ndonner le nouveau sexe\n");
            gets(tab[i].sexe);

            printf("\n\ndonner la nouvelle date de naissance\n");
            saisie_date();

            printf("\n\ndonner la nouvelle adresse\n");
            saisie_adresse();

            printf("\n\ndonner le nouveau num%cro du tel\n", 130);
            gets(tab[i].tel);

            printf("\n\ndonner la nouvelle %ctat civile\n", 130);
            gets(tab[i].etat_civil);

            printf("\n\ndonner le nouveau nombre d'enfants\n");
            scanf("%d", &tab[i].nombre_enfants);
            getchar();

            ctr = 1;
            printf("\n \n l'employ%c est modifi%c", 130, 130);
            break;
        }
        i++;
    }
    if(ctr == 0) printf("l'employ%c ne travaille pas dans l'entreprise", 130);
}

int affichage_menu()
{
    int choix_menu;
    printf("\n\n \t\t\t\t\t\t ***  MENU  ***\n\n\n\n");
    printf("\t\t\t**********************************\n");
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 1. ajouter un employ%c          *\n", 130);
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 2. modifier un employ%c         *\n", 130);
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 3. supprimer un employ%c        *\n", 130);
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 4. afficher un employ%c         *\n", 130);
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 5. afficher tous les employ%cs  *\n", 130);
    printf("\t\t\t*                                *\n");
    printf("\t\t\t* 6. sortir                      *\n");
    printf("\t\t\t*                                *\n");
    printf("\t\t\t**********************************\n\n\n");
    printf("quel est votre choix?\n");
    scanf("%d", &choix_menu);
    getchar();
    printf("\n\n");
    return choix_menu;
}



