#ifndef DEF_FONCTIONS_H_INCLUDED
#define DEF_FONCTIONS_H_INCLUDED
#define maximum 1000


typedef struct {
    char jour[20];
    char mois[20];
    char annee[40];
} date;

typedef struct {
    char gouvernorat[200];
    char ville[200];
    char rue[200];
    char code_postal[40];
} adresse;

typedef struct {
    char identifiant[100];
    char n_cin[12];
    char nom[100];
    char prenom[100];
    char sexe[50];
    date date_de_naissance;
    adresse adr;
    char tel[80];
    char etat_civil[100];
    int nombre_enfants;
} employe;

date saisie_date();
adresse saisie_adresse();
void ajouter_employe(employe tab[maximum],int n);
void afficher_employe(employe x, employe tab[maximum], int n);
void modifier_employe(employe x, employe tab[maximum], int n);
void supprimer_employe(employe x, employe tab[maximum], int n);
int affichage_menu();

#endif // DEF_FONCTIONS_H_INCLUDED
