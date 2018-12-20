#ifdef CHANGED
#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "copyright.h"
#include "bitmap.h"

// Must be a singleton (Create with machine in Initialize)
class PageProvider:dontcopythis{
    public:
        PageProvider();     // Allocate PageProvider
        ~PageProvider();    // De-allocate PageProvider
        
        int GetEmptyPage();         // Récupérer le numéro d’une page libre et l’initialise à 0 (par memset)
        void ReleasePage(int addr); // Libérer une page obtenue par GetEmptyPage
        int NumAvailPage();         // Retourne le nombre de page disponible
    private:
        BitMap *bitmap;
};

#endif //PAGEPOVIDER_H
#endif 