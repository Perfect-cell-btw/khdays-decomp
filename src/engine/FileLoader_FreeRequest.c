/* Returns a finished load request to the file loader's free list (gFileLoader + 0x18). */

extern int gFileLoader;

void FileLoader_FreeRequest(int *request) {
    *request = *(int *)((char *)&gFileLoader + 0x18);
    *(int *)((char *)&gFileLoader + 0x18) = (int)request;
}
