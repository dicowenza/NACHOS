#ifdef CHANGED

/**
 * Prcédure de lancement :
 * 1. Aller dans le répertoire code.
 * 2. Compiler le projet en utilisant la commande make.
 * 3. Lancer l'éxecutable avec la commande : ./userprog/nachos -x test/putint
 * 
 * Sortie attendue :
 * 1. Affichage des entiers au limites.
 * 2. Affichage de l'entier saisi.
 */

#include "syscall.h"

void print(int start, int end) {
	int i;
    for (i = start; i < end; i++) {
        PutInt(i);
        PutString("\n");
    }
}

void get() {
    int n;
    PutString("Veuillez saisir un nombre entier [-2 147 483 648, 2 147 483 647] : ");
    n = GetInt();
    // Si l'utilisateur saisit un nombre en dehors des limites autorisés,
    // le caractère saisit sera incohérent (integer overflow)
    PutString("Vous avez saisit le nombre : ");
    PutInt(n);
    PutString("\n");
}

int main() {
	print(2147483645, 2147483647);
    print(-2147483647, -2147483645);
    // /!\ Be careful on the limits
    get();
	return 0;
}

#endif
