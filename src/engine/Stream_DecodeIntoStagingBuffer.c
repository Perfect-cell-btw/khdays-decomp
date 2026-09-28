/* Prepares the 0x8000-byte staging buffer at +0x594, runs FileLoader_LoadSync into it and, on
 * success, rounds the returned length up to a multiple of four before recording it at +0
 * and +8 and handing over to Script_Start. */
extern int FileLoader_LoadSync(int a, void *b, int size);
extern int Script_Start(char *o, int c, int d);

int Stream_DecodeIntoStagingBuffer(char *o, int a, int c, int d) {
    int n;
    *(int *)(o + 0x590) = 0x8000;
    n = FileLoader_LoadSync(a, o + 0x594, *(int *)(o + 0x590));
    if (n < 0) {
        return 0;
    }
    if (n % 4 != 0) {
        n += 4 - n % 4;
    }
    *(int *)o = n;
    *(int *)(o + 8) = n;
    return Script_Start(o, c, d);
}
