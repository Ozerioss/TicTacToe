
#include <stdio.h>
#include <stdlib.h>

char matrice[3][3];  // on utilise une matrice de char car elle utilise moins de mémoire

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

// On initialise la matrice avec des espaces
void initialisation_matrice(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrice[i][j] =  ' ';
}

// Methode qui récupère les coordonnées entrées par le joueur et vérifie si le mouvement est bien valide
void mouvement_joueur(void)
{
  int x, y;

  printf("Entrez les coordonnées X,Y pour votre tour : ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrice[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    mouvement_joueur();
  }
  else matrice[x][y] = 'X';   // Si le mouvement est bien valide on pose 'X' dans les coordonnées données
}

// Méthode permettant d'avoir un mouvement de l'ordinateur
void mouvement_ordinateur(void)
{
  int i, j;
  for(i=0; i<3; i++){   // vérifie que le mouvement est valide
    for(j=0; j<3; j++)
      if(matrice[i][j]==' ') break;
    if(matrice[i][j]==' ') break;
  }

  if(i*j==9)  {
    printf("égalité\n");
    exit(0);
  }
  else
    matrice[i][j] = 'O';
}

// Méthode pour afficher la matrice
void afficher_matrice(void)
{
  int x;

  for(x=0; x<3; x++) {
    printf(" %c | %c | %c ",matrice[x][0],
            matrice[x][1], matrice[x][2]);
    if(x!=2) printf("\n---|---|---\n");   // Pour avoir une structure ressemblant celle d'un tableau de 3 par 3
  }
  printf("\n");
}

// Méthode pour déterminer s'il y'a un gagnant
char check(void)
{
  int i;

  for(i=0; i<3; i++)  // vérifie s'il y'a un gagnant sur les lignes
    if(matrice[i][0]==matrice[i][1] &&
       matrice[i][0]==matrice[i][2]) return matrice[i][0];

  for(i=0; i<3; i++)  // vérifie s'il y'a un gagnant sur les colomnes
    if(matrice[0][i]==matrice[1][i] &&
       matrice[0][i]==matrice[2][i]) return matrice[0][i];

  // Finalement pour vérifier sur les diagonales
  if(matrice[0][0]==matrice[1][1] &&
     matrice[1][1]==matrice[2][2])
       return matrice[0][0];

  if(matrice[0][2]==matrice[1][1] &&
     matrice[1][1]==matrice[2][0])
       return matrice[0][2];

  return ' ';
}


int main(void)
{
  char done;

  printf("Jeu de morpion \n");
  printf("Vous jouez contre l'ordinateur \n");

  done =  ' ';
  initialisation_matrice();

  do {
    afficher_matrice();
    mouvement_joueur();
    done = check();
    if(done!= ' ') break;
    mouvement_ordinateur();
    done = check(); // vérifie s'il y'a un gagnant
  } while(done== ' ');

  afficher_matrice(); // Affiche la matrice

  if(done=='X') printf("Vous gagnez !\n");
  else printf("L'ordinateur gagne !\n");

  return 0;
}


