#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonctions.h";

/* D�clarations des variables */
	int l, c; // dimensions du tableau : nombre de lignes et de colonnes
	int i, j;  // indices du tableau ( vont servir aussi de compteur)
	const int TAILLE=20;
	char tab[TAILLE][TAILLE]; // tableau initial : quelque soit le jeu,  le tableau ne doit d�passer ces dimensions
    char grille[TAILLE][TAILLE]; // grille du jeu - contenant les bombes
	int bombes;

	int NnBombes = (l+c)%3;

//===================================================================
/* Le joueur choisi les dimensions de la grille du jeu */

	void ChoixTaille(){

	printf("saisir le nombre de lignes et de colonnes (max 20): ");
	scanf("%d", &l);
	scanf("%d", &c);

	// contr�le de la fuite m�moire
	while(l>20 || c>20){
        printf(" nombres inferieurs a 20 ! \n");
        scanf("%d", &l);
        scanf("%d", &c);
	} // fin while dimensions d�bordantes

	} // fin fonction  ChoixTaille()
//===================================================================

//===================================================================
	/* Affiche une premiere vue du jeu */
	void TableauInitial(){

    // sinon, si les dimensions corrrespondent
     for(i=0; i<l;i++){ // boucle de cr�ation les lignes
		for(j=0; j<c; j++){ // boucle qui va ins�rer les colonnes
                tab[i][j] = '*';
                grille[i][j] = '0';
        /* penser � afficher les lettres facilitant le choix de la case */
			printf("|%c", tab[i][j]);
		} // fin for j
		printf("|\n");
	}// fin for i
	printf("\n");

	} // fin fonction TableauInitial()
//=====================================================================

//===================================================================
	/* Remplit le tableau par des bombes */
    void RemplirTableau(){
    // utiliser la grille

    for(i=0; i<NnBombes; i++){
        for(j=0; j<NnBombes; j++){
                if(l>c)
            grille[i][j] = rand()%l;
            grille[i][j] = rand()%c;

            //printf("%d", grille[i][j]);
        }
    }

    // pla�ons les bombes
    if(grille[i][j] == '0'){
        grille[i][j] = 'B';
    }
} // fin fonction RemplirTableau()
//===================================================================

//===================================================================
int BombesAutour(){
    int n = 0;
    if(grille[i][j] == 'B'){
      printf("Vous avez perdu \n");
        for(i=0; i<l; i++){
            for(j=0; j<c; j++){
                printf("%c ", grille[i][j]); // puis affichela grille en d�voilant les cases
            } printf("\n");
        }
    }
    else // si dans la case il n' y a pas de bombe, alors on calcule le nombre de bombes autour
    if(i==0){
            if(j==0){
                if(grille[i][j+1]=='B')
                    n++;
                if(grille[i+1][j]=='B')
                      n++;
                if(grille[i+1][j+1]=='B')
                      n++;
            } // fin if premiere colonne
            else{
                if(j==c){
                    if(grille[i][j-1]=='B')
                        n++;
                    if(grille[i+1][j-1]=='B')
                        n++;
                    if(grille[i+1][j]=='B')
                        n++;
                } // fin if derni�re colonne
                else{
                    if(grille[i][j-1]=='B')
                        n++;
                    if(grille[i][j+1]=='B')
                        n++;
                    if(grille[i+1][j-1]=='B')
                        n++;
                    if(grille[i+1][j]=='B')
                        n++;
                    if(grille[i+1][j+1]=='B')
                        n++;
                } // fin pas derniere colonne
            } // fin if pas premiere colonne

    } // fin if de premi�re ligne
    else {  // Pas premiere ligne
        if(i==l){ // derni�re ligne
            if(j==0){ // premi�re colonne
                if(grille[i-1][j]=='B')
                    n++;
                if(grille[i-1][j+1]=='B')
                      n++;
                if(grille[i][j+1]=='B')
                      n++;
            } // fin if premi�re colonne
            else{ // derni�re colonne
                if(j==c){
                if(grille[i-1][j-1]=='B')
                    n++;
                if(grille[i-1][j]=='B')
                      n++;
                if(grille[i][j-1]=='B')
                      n++;
                } // fin if derni�re colonne
            else{ // si pas derni�re colonne
                if(grille[i-1][j-1]=='B')
                    n++;
                if(grille[i-1][j]=='B')
                      n++;
                if(grille[i-1][j+1]=='B')
                      n++;
                if(grille[i][j-1]=='B')
                      n++;
                if(grille[i][j+1]=='B')
                      n++;
            } // fin si pas derni�re colonne
            } // fin if pas premi�re colonne
        }// fin if derni�re ligne

    else{ // sinon de tous ces cas
        if(grille[i-1][j-1]=='B')
            n++;
        if(grille[i-1][j]=='B')
            n++;
        if(grille[i-1][j+1]=='B')
            n++;
        if(grille[i][j-1]=='B')
            n++;
        if(grille[i][j+1]=='B')
            n++;
        if(grille[i+1][j-1]=='B')
            n++;
        if(grille[i+1][j]=='B')
            n++;
        if(grille[i+1][j+1]=='B')
            n++;
    }

    }

    return(n);


}
//===================================================================


//===================================================================
void AfficherCase(){

int i, j; // indices de la case
    printf("ligne et colonne : \n");
    scanf("%d", &i);
    scanf("%d", &j);
while(i>l || j>c){
  printf("Nombres inferieur ou egal a l et c ! \n\n");
    scanf("%d", &i);
    scanf("%d", &j);
}

    BombesAutour();
    if(n!=0)
       printf("%d \n", n); // affiche le nombre de bombes autour

       else{ // // sinon pas de bombe
	 tab[i][j] = 'v';
       }


}
//==================================================================


/////////// Programme principal //////////
int  main(){

	ChoixTaille();
	TableauInitial();
	RemplirTableau();

} // fin main

// d�claration des fonctions

int AfficheCase(int l, int c){
    // affiche la case l*c
    printf("ligne de la case : ");
    scanf("%d", &l);
    printf("colonne de la case :");
    scanf("%d", &c);
    while(l>20 || c>20){
        printf("ligne de la case : ");
        scanf("%d", &l);
        printf("colonne de la case :");
        scanf("%d", &c);
    }
    char grille[TAILLE][TAILLE]; /* tableau des bombes */
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            grille[i][j] = (char)rand()%c;
        }
    }

    printf()

}


