#ifdef CHANGED

PageProvider::PageProvider() {
    bitmap = new Bitmap(NumPhysPages);
}

PageProvider::~PageProvider() {
    delete bitmap;
}

int GetEmptyPage() {
    int empty_page = bitmap->Find();
    int addr = (empty_page * PageSize);
    void *ptr = &(machine->mainMemory[addr]);
    memset(ptr, 0, PageSize);
    return addr;
}

void ReleasePage(int page) {
    bitmap->Clear(page);
}

int NumAvailPage() {
    return bitmap->NumClear();
}

#endif
