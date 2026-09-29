/* Returns a finished load request to the file loader's free list (data_0204bbfc + 0x18). */

extern int data_0204bbfc;

void FileLoader_FreeRequest(int *request) {
    *request = *(int *)((char *)&data_0204bbfc + 0x18);
    *(int *)((char *)&data_0204bbfc + 0x18) = (int)request;
}
