extern int Ov022_StepAnchorDelta(int self, void *out);
extern void SceneNode_Enable(int a);
extern int Session_GetLocalPlayerIndex(void);

typedef struct { unsigned char b0 : 1, b1 : 1; } Flags;

int Ov087_PollHitAndFlagLanded(int self) {
    int v[3];
    int r;
    Ov022_StepAnchorDelta(self, v);
    *(int *)(self + 0x58) = v[1];
    r = (*(int (**)(int))(self + 0x668))(self);
    ((Flags *)(self + 0x694))->b1 = (unsigned char)r;
    if (((Flags *)(self + 0x694))->b1) {
        int *p;
        *(unsigned long long *)self |= 0x2000000000000ULL;
        p = *(int **)(self + 0x20);
        if ((*p & 0x20) == 0) {
            SceneNode_Enable((int)p + 4);
        }
        if (Session_GetLocalPlayerIndex() == 0) {
            *(unsigned long long *)((char *)self + 0x464) |= 2;
        }
    }
    return 0;
}
