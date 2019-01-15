#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


#define TAILLE 20;
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int i,j;
int l, c;
char jeu[TAILLE][TAILLE]; // grille du jeu -affiché au joueur s'il n a pas encore perdu
char tab[TAILLE][TAILLE]; // grille contenant les mines
int Nbmines;
int compter;

#endif // FONCTIONS_H_INCLUDED

void ChoixTableau(){ // Début du jeu - choix de la taille du tableau
 printf("Nombre de taille (max %d) :", TAILLE);
 scanf("%d", c);
 printf("Nombre de lignes (max %d) :", TAILLE);
 scanf("%d", l);

while(l>20 || c>0){
 printf("Nombre de taille (max %d) :", TAILLE);
 scanf("%d", c);
 printf("Nombre de lignes (max %d) :", TAILLE);
 scanf("%d", l);
}
}


int tablaux(){ // tableaux du jeu initialisation
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
        jeu[i][j] = 'C'; // C pour caché - à découvrir par le joueur
        tab[i][j] = 'R'  // R pour Rien - on placera dessus les mines
        }
    }

for(compter=0; compter<Nbmines; compter++){ // rempli les mines dans la grille des mines
    i=rand()%l;
    j=rand()%c;
    if(tab[i][j]=='R')
        tab[i][j] = 'M';
    Nbmines++;
}
}

void AfficheJeu(){ // affiche la grille du jeu
for(i=0; i<l; i++){
    for(j=0; j<c; j++){
        printf("%c", jeu[i][j]);
    }
    printf("\n");
}
}


int CaseMines(int i, int j){ // si le joueur a ouvert une case qu a une mine
    if(tab[i][j] == 'M'){
        printf("Vous avez perdu");
         for(i=0; i<l; i++){
            for(j=0; j<c; j++){
                printf("%c", tab[i][j]);
            }
            printf("\n");
         }
         return 0;
    }
}

int MinesAutour(int tab[l][c], int x, int y){ // calcule le nombre de mines autour de la case
int minesAutour = 0;

for(i=y-(y>0); i<l && i<y+1; i++){
    for(j=x-(x>0); jc && j<x+1; j++){
        if(tab[i][j] == 'M')
            minesAutour++;
    }
}
return minesAutour;
}


int Jouer(){

printf("quelle ligne ? :");
scanf("%d", cl);
printf("quelle colonne ? :");
scanf("%d", cc);

while(cl<0 || cl>l || cc<0 || cc>c){
printf("quelle ligne ? :");
scanf("%d", cl);
printf("quelle colonne ? :");
scanf("%d", cc);
}

if(tab[cl][cc] == 'C'){
    CaseMines(i, j);
}
    MinesAutour(tab[l][c], x, y);


}

