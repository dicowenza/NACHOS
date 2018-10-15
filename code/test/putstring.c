#ifdef CHANGED

/**
 * Prcédure de lancement :
 * 1. Aller dans le répertoire code.
 * 2. Compiler le projet en utilisant la commande make.
 * 3. Lancer l'éxecutable avec la commande : ./userprog/nachos -x test/putstring
 * 
 * Sortie attendue :
 * 1. Affichage de l'alphabet.
 * 2. Affichage de la chaîne saisie.
 */

#include "syscall.h"

void get() {
	char str[100];
    PutString("1. Veuillez entrer une chaine de caractère (42 char max) : ");
    GetString(str, 43);
	// L'utilisateur ne doit pas dépasser la limite de 43 caractère, sans quoi le
	// reste de la chaîne sera exécuter par le terminal après l'extinction de NACHOS.
	PutString("\n");
    PutString("2. La chaine de caractere saisie est : ");
    PutString(str);
    PutString("\n");
}

int main() {
	// On note que MAX_STRING_SIZE = 10
	PutString("Alphabet : abcdefghijklmnopqrstuvwxyz\n");
	get();
	return 0;
}

#endif
