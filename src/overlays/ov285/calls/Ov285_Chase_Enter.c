typedef unsigned char u8;

struct State {
    char *pActor;
    char pad04[0x14];
    void *pTarget;      /* 0x18 */
    char pad1c[0xc];
    int nPhase28;       /* 0x28 */
    int nTimer2c;       /* 0x2c */
};

struct Node {
    void *pScene;
    struct State *pState;
    char pad08[0x18];
    signed char bSlot;
};

extern void *Ov107_FindNearestObject(char *actor, int mode);
extern void Ov107_PostTagUpdate(char *actor, int a, int b);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(struct Node *node, int slot, void *next);

extern void Ov285_Chase_Tick(void);

void Ov285_Chase_Enter(struct Node *node)
{
    struct State *st;
    void *pTarget;

    st = node->pState;
    pTarget = Ov107_FindNearestObject(st->pActor, 0);
    st->pTarget = pTarget;
    if (pTarget == 0) {
        *(u8 *)(st->pActor + 0x1c7) = 2;
        SetIndexedSlot(node, node->bSlot, 0);
        return;
    }
    st->nPhase28 = 0;
    Ov107_PostTagUpdate(st->pActor, 1, 1);
    st->nTimer2c = RandNextScaled(0x3001) + 0x1000;
    SetIndexedSlot(node, node->bSlot, (void *)Ov285_Chase_Tick);
}
