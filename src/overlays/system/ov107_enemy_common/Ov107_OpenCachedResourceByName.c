/* Look a resource up by name in the cache list at +0x4c, and open it on a miss.
 * On a hit the cached handle is returned. On a miss a new entry is inserted, the
 * name is duplicated into a fresh allocation, and Msg_OpenContainerAndReadHeader opens the
 * resource with mode 0xb. Returns 0 when the cache itself does not exist. */
extern int data_ov107_020cbf1c;

extern int *List_First(void *list);
extern int *List_Next(void *list);
extern int *List_InsertSorted(void *list, int a, int b);
extern int strcmp(const char *a, const char *b);
extern unsigned int strlen(const char *s);
extern void *CallocInstance(unsigned int size);
extern void strcpy(void *dst, const char *src);
extern int Msg_OpenContainerAndReadHeader(const char *name, int mode);

int Ov107_OpenCachedResourceByName(const char *name) {
    char *cache = *(char **)&data_ov107_020cbf1c;
    int *entry;

    if (cache != 0) {
        entry = List_First(cache + 0x4c);
        while (entry != 0) {
            if (strcmp((char *)entry[1], name) == 0) {
                return entry[0];
            }
            entry = List_Next(cache + 0x4c);
        }

        entry = List_InsertSorted(cache + 0x4c, 8, 100);
        entry[1] = (int)CallocInstance(strlen(name) + 1);
        strcpy((void *)entry[1], name);
        entry[0] = Msg_OpenContainerAndReadHeader(name, 0xb);
        return entry[0];
    }

    return 0;
}
