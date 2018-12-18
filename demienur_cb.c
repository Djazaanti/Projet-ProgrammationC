#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonctions.h";

/* Déclarations des variables */
	int l, c; // dimensions du tableau : nombre de lignes et de colonnes
	int i, j;  // indices du tableau ( vont servir aussi de compteur)
	const int TAILLE=20;
	char tab[TAILLE][TAILLE]; // tableau initial : quelque soit le jeu,  le tableau ne doit dépasser ces dimensions
    char grille[TAILLE][TAILLE]; // grille du jeu - contenant les bombes
	int bombes;

	int NnBombes = (l+c)%3;

//===================================================================
/* Le joueur choisi les dimensions de la grille du jeu */

	void ChoixTaille(){

	printf("saisir le nombre de lignes et de colonnes (max 20): ");
	scanf("%d", &l);
	scanf("%d", &c);

	// contrôle de la fuite mémoire
	while(l>20 || c>20){
        printf(" nombres inferieurs a 20 ! \n");
        scanf("%d", &l);
        scanf("%d", &c);
	} // fin while dimensions débordantes

	} // fin fonction  ChoixTaille()
//===================================================================

//===================================================================
	/* Affiche une premiere vue du jeu */
	void TableauInitial(){

    // sinon, si les dimensions corrrespondent
     for(i=0; i<l;i++){ // boucle de création les lignes
		for(j=0; j<c; j++){ // boucle qui va insérer les colonnes
                tab[i][j] = '*';
                grille[i][j] = '0';
        /* penser à afficher les lettres facilitant le choix de la case */
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

    // plaçons les bombes
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
                printf("%c ", grille[i][j]); // puis affichela grille en dévoilant les cases
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
                } // fin if dernière colonne
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

    } // fin if de première ligne
    else {  // Pas premiere ligne
        if(i==l){ // dernière ligne
            if(j==0){ // première colonne
                if(grille[i-1][j]=='B')
                    n++;
                if(grille[i-1][j+1]=='B')
                      n++;
                if(grille[i][j+1]=='B')
                      n++;
            } // fin if première colonne
            else{ // dernière colonne
                if(j==c){
                if(grille[i-1][j-1]=='B')
                    n++;
                if(grille[i-1][j]=='B')
                      n++;
                if(grille[i][j-1]=='B')
                      n++;
                } // fin if dernière colonne
            else{ // si pas dernière colonne
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
            } // fin si pas dernière colonne
            } // fin if pas première colonne
        }// fin if dernière ligne

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

// déclaration des fonctions

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


