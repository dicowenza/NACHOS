#ifdef CHANGED

/**
 * Prcédure de lancement :
 * 1. Aller dans le répertoire code.
 * 2. Compiler le projet en utilisant la commande make.
 * 3. Lancer l'éxecutable avec la commande : ./userprog/nachos -x test/putchar
 * 
 * Sortie attendue :
 * 1. Affichage des caractères abcd.
 * 2. Affichage du caractère saisi.
 */

#include "syscall.h"

void print(char c, int n) {
	int i;
	for (i = 0; i < n; i++)
		PutChar(c + i);
	PutChar('\n');
}

void get() {
	int c;
    PutString("Veuillez entrer un caractère : ");
    c = GetChar();
	// Problème : en saisissant un caractère et en appuyant sur entrée, 
	// le terminal va stocker dans son buffer le caractère '\n'.
	PutChar('\n');
    PutString("Le caractere saisie est : ");
    PutChar(c);
	// En lancant un appel a GetString ici, l'entrée standard prendra en compte le buffer 
	// du terminal (le caractère '\n' précédemment saisit). Même remarque si l'utilisateur 
	// saisit plus d'un caractère.
    PutChar('\n');
}

int main() {
	print('a', 4);
	get();
	return 0;
}

#endif
