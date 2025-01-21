#include <stdio.h>
#include <stdlib.h>
typedef struct Livre{
    char *titre_livre;
    float prix;

}livre;

livre creation_livre(){
    livre l1;
    l1.titre_livre=(char*)malloc(40*sizeof(char));
    printf("Entrer le titre de livre ");
    scanf("%s",l1.titre_livre);
    printf("Entrer le prix de livre ");
    scanf("%f",&l1.prix);
    return l1;
}
livre* creer_liste_livres(int nbr_livres){
    livre* ptr;
    ptr=(livre *)malloc(nbr_livres*sizeof(livre));
    int i;
    for(i=0;i<nbr_livres;i++){
        ptr[i]=creation_livre();

    }
    return ptr;
}
void afficher_par_prix(livre* liste_livres, int nbr_livres, float prix_min){
    int i;
    for(i=0;i<nbr_livres;i++){
        if(liste_livres[i].prix>prix_min){
            printf("%s ",liste_livres[i].titre_livre);
        }
    }

}

 int chercher_livre_par_titre_et_afficher(livre* liste, int nbr_livres, char* titre){
     int i,dr=0;
     for(i=0;i<nbr_livres;i++){
        if(strcmp(liste[i].titre_livre, titre) == 0){
            printf("Titre:%s ",liste[i].titre_livre);
            printf("Prix:%f ",liste[i].prix);
            dr=1;
            return i;
        }

     }

    return -1;






 }



int main()
{
    int nbr_livres,resultat;
    float prix_min;
    char titre[40];
    livre lv;
    lv=creation_livre();
    printf("Entrer le nombre de livres ");
    scanf("%d",&nbr_livres);

    livre* lvs=creer_liste_livres(nbr_livres);
    printf("Entrer le prix min ");
    scanf("%f",&prix_min);
    afficher_par_prix(lvs,nbr_livres, prix_min);
    printf("Entrer le titre de livre ");
    scanf("%s",titre);
    resultat=chercher_livre_par_titre_et_afficher(lvs,nbr_livres,titre);





    return 0;
}
