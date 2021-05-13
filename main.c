#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "def_fonctions.h"

int main()
{
    int choix_menu = 0, n = 0, i;
    char nombre_enfants[200];
    employe tab[maximum];
    employe x;
    FILE *fp;

    fp = fopen("employe.txt","r");
    if (fp == NULL)
        printf("le fichier n'existe pas");
    else {
        i = 0;
        while (fgetc(fp) != EOF)
        {
            fseek(fp, -1L, SEEK_CUR);
            i++;
            fgets(x.identifiant, sizeof(x.identifiant), fp);
            x.identifiant[strcspn(x.identifiant, "\n")] = 0;
            
            fgets(x.n_cin, sizeof(x.n_cin), fp);
            x.n_cin[strcspn(x.n_cin, "\n")] = 0;
            
            fgets(x.nom, sizeof(x.nom), fp);
            x.nom[strcspn(x.nom, "\n")] = 0;
            
            fgets(x.prenom, sizeof(x.prenom), fp);
            x.prenom[strcspn(x.prenom, "\n")] = 0;
            
            fgets(x.sexe, sizeof(x.sexe), fp);
            x.sexe[strcspn(x.sexe, "\n")] = 0;
            
            fgets(x.date_de_naissance.jour, sizeof(x.date_de_naissance.jour), fp);
            x.date_de_naissance.jour[strcspn(x.date_de_naissance.jour, "\n")] = 0;
            
            fgets(x.date_de_naissance.mois, sizeof(x.date_de_naissance.mois), fp);
            x.date_de_naissance.mois[strcspn(x.date_de_naissance.mois, "\n")] = 0;
            
            fgets(x.date_de_naissance.annee, sizeof(x.date_de_naissance.annee), fp);
            x.date_de_naissance.annee[strcspn(x.date_de_naissance.annee, "\n")] = 0;
            
            fgets(x.adr.gouvernorat, sizeof(x.adr.gouvernorat), fp);
            x.adr.gouvernorat[strcspn(x.adr.gouvernorat, "\n")] = 0;
            
            fgets(x.adr.ville, sizeof(x.adr.ville), fp);
            x.adr.ville[strcspn(x.adr.ville, "\n")] = 0;

            fgets(x.adr.rue, sizeof(x.adr.rue), fp);
            x.adr.rue[strcspn(x.adr.rue, "\n")] = 0;

            fgets(x.adr.code_postal, sizeof(x.adr.code_postal), fp);
            x.adr.code_postal[strcspn(x.adr.code_postal, "\n")] = 0;

            fgets(x.tel, sizeof(x.tel), fp);
            x.tel[strcspn(x.tel, "\n")] = 0;
            
            fgets(x.etat_civil, sizeof(x.etat_civil), fp);
            x.etat_civil[strcspn(x.etat_civil, "\n")] = 0;
            
            fgets(nombre_enfants, sizeof(nombre_enfants), fp);
            nombre_enfants[strcspn(nombre_enfants, "\n")] = 0;
            x.nombre_enfants = atoi(nombre_enfants);
            tab[i-1] = x;
        }
        fclose(fp);
        n = i;
        printf("nombre d'employ%cs=%d\n", 130,n);
     }



    while(1) {
        choix_menu = affichage_menu();

        switch(choix_menu){

            case 1:
                ajouter_employe(tab, &n);
                break;
        
            case 2:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c modifier\n", 130, 130, 133);
                gets(x.n_cin);
                modifier_employe(x, tab, n);
                break;
        
            case 3:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c supprimer:\n", 130, 130, 133);
                gets(x.n_cin);
                supprimer_employe(x, tab, &n);
                break;
        
            case 4:
                printf("\n\ndonner le num%cro de la CIN de l'employ%c %c afficher:\n",130,130,133);
                gets(x.n_cin);
                afficher_employe(x, tab, n);
                break;
            
            case 5:
                afficher_tous_employes(tab, n);
                break;

            case 6:
                printf("a bient%ct......", 147);
                fp = fopen("employe.txt", "w");
                for (int i = 0; i < n; i++) {
                    fprintf(fp, "%s\n", tab[i].identifiant);
                    fprintf(fp, "%s\n", tab[i].n_cin);
                    fprintf(fp, "%s\n", tab[i].nom);
                    fprintf(fp, "%s\n", tab[i].prenom);
                    fprintf(fp, "%s\n", tab[i].sexe);
                    fprintf(fp, "%s\n", tab[i].date_de_naissance.jour);
                    fprintf(fp, "%s\n", tab[i].date_de_naissance.mois);
                    fprintf(fp, "%s\n", tab[i].date_de_naissance.annee);
                    fprintf(fp, "%s\n", tab[i].adr.gouvernorat);
                    fprintf(fp, "%s\n", tab[i].adr.ville);
                    fprintf(fp, "%s\n", tab[i].adr.rue);
                    fprintf(fp, "%s\n", tab[i].adr.code_postal);
                    fprintf(fp, "%s\n", tab[i].tel);
                    fprintf(fp, "%s\n", tab[i].etat_civil);
                    fprintf(fp, "%d\n", tab[i].nombre_enfants);
                }
                fclose(fp);
                Sleep(3000);
                exit(1);

            default:
                printf("choix incorrect!");
        }
    } 
    return 0;
}
