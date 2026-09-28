typedef struct { int w[11]; } Xform44;

typedef struct {
    int field_00;
    Xform44 xform;
    char pad[0x5c - 0x30];
    int flags;
} Node;

typedef struct { Node *node; } Entry;

extern int CreateRegistryEntry(int param_1, unsigned int param_2, unsigned int param_3,
                          int param_4, int param_5, Entry **param_6);
extern void SetSubitemState(int obj, unsigned short idx, int blend, int zero);
extern void RefreshObjectCallbacks(int *ptr, int arg);
extern void Ov107_TaskTeardown_FlagOwner(void);
extern void Ov107_NodeXformTaskStart(void);

int Ov107_CreateNodeXformTask(int taskList, Node *node, int mode, int blend, Xform44 *m)
{
    Entry *entry;
    int r = CreateRegistryEntry(taskList, 100, 4, (int)&Ov107_NodeXformTaskStart,
                           (int)&Ov107_TaskTeardown_FlagOwner, &entry);
    entry->node = node;
    entry->node->flags |= 2;
    entry->node->xform = *m;
    for (int i = 0; i < 5; i++) {
        if (mode & (1 << i))
            SetSubitemState((int)node, i, blend, 0);
    }
    RefreshObjectCallbacks((int *)node, 0);
    return r;
}
