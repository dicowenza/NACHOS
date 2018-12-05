#ifdef CHANGED
#include "pageprovider.h"
#include "machine.h"
#include "system.h"





PageProvider::PageProvider() {
    bitmap = new BitMap(NumPhysPages);
}

PageProvider::~PageProvider() {
    delete bitmap;
}

int PageProvider::GetEmptyPage() {
    int empty_page = bitmap->Find();
    int addr = (empty_page * PageSize);
    void *ptr = &(machine->mainMemory[addr]);
    memset(ptr, 0, PageSize);
    return addr;
}

void PageProvider::ReleasePage(int page) {
    bitmap->Clear(page);
}

int PageProvider::NumAvailPage() {
    return bitmap->NumClear();
}

#endif
