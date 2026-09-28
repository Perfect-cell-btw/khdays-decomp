extern void FreeChannel(void *p);
extern void RemoveCommandByPlayer(void *list, void *node);
extern void FreePlayer(void *p);

extern char data_0204b620[];
extern char *data_0204ad8c[];

struct S {
    char _0[0x110];
    int flags;
    char _114[0x168 - 0x114];
    void (*x168)(void *);
};

void OSi_DestroyThread(struct S *p)
{
    char *q;
    if (((p->flags << 31) >> 31) == 0) return;
    FreeChannel(p);
    p->x168(p);
    RemoveCommandByPlayer(data_0204b620, p);
    q = data_0204ad8c[1];
    if (q != 0) {
        RemoveCommandByPlayer(q + 0x4e0, p);
    }
    FreePlayer(p);
}
