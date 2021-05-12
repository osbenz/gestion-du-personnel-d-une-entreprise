#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def_fonctions.h"

int main()
{

    int choix_menu = 0, n = 0, ctr = 1, i;
    employe tab[maximum];
    employe x;
    FILE *fp;


    fp = fopen("employe.txt","rt");
    if (fp == NULL)
        printf("le fichier n'existe pas");
    else {
        i = 0;
        while (!feof(fp))
        {
            fscanf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %d", tab[i].identifiant,
                   tab[i].n_cin, tab[i].nom,tab[i].prenom, tab[i].sexe, tab[i].date_de_naissance.jour,
                   tab[i].date_de_naissance.mois, tab[i].date_de_naissance.annee,
                   tab[i].adr.gouvernorat, tab[i].adr.ville, tab[i].adr.rue, tab[i].adr.code_postal,
                   tab[i].tel, tab[i].etat_civil, &tab[i].nombre_enfants);
            i++;
        }
        fclose(fp);
        n = i;
     }



    do {
        choix_menu = affichage_menu();

        switch(choix_menu){

            case 1:
                ajouter_employe(tab, n);
                break;
        
            case 2:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c modifier\n", 130, 130, 133);
                gets(x.n_cin);
                modifier_employe(x, tab, n);
                break;
        
            case 3:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c supprimer:\n", 130, 130, 133);
                gets(x.n_cin);
                supprimer_employe(x, tab, n);
                break;
        
            case 4:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c afficher:\n",130,130,133);
                gets(x.n_cin);
                afficher_employe(x, tab, n);
                break;

            case 5:
                printf("a bient%ct", 147);
                ctr = 0;
                fp = fopen("employe.txt", "wt");
                for (int i = 0; i < n; i++) fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %d\n", tab[i].identifiant,
                                            tab[i].n_cin, tab[i].nom, tab[i].prenom, tab[i].sexe, tab[i].date_de_naissance.jour,
                                            tab[i].date_de_naissance.mois,tab[i].date_de_naissance.annee, tab[i].adr.gouvernorat,
                                            tab[i].adr.ville, tab[i].adr.rue, tab[i].adr.code_postal, tab[i].tel,
                                            tab[i].etat_civil, tab[i].nombre_enfants);
                fclose(fp);
                exit(1);

            default:
                printf("choix incorrect!");
                break;
        }

    } while(ctr != 0);

    return 0;
}
