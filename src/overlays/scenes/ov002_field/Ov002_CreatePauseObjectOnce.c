/* Create the pause object once: while the slot at +0x8c94 still holds the empty
 * marker -1, quiesce with Ov002_SetLazyClassEnabled(0) and instantiate the class into
 * it. The 0x5c-byte parameter block is left uninitialised apart from word 1,
 * which carries the same -1. */
typedef struct {
    char pad0000[0x8c94];
    int nPauseObject;           /* +0x8c94, -1 = none */
} Ov002RootContext;

extern void Ov002_SetLazyClassEnabled(int mode);
extern int InstantiateClass(const void *cls, void *params);

extern Ov002RootContext *data_ov002_0207fa00;
extern char data_ov002_0207e8c8[];

void Ov002_CreatePauseObjectOnce(void) {
    int params[23];
    Ov002RootContext *root = data_ov002_0207fa00;

    int *slot = &root->nPauseObject;

    if (*slot == -1) {
        params[1] = -1;
        Ov002_SetLazyClassEnabled(0);
        *slot = InstantiateClass(data_ov002_0207e8c8, params);
    }
}
