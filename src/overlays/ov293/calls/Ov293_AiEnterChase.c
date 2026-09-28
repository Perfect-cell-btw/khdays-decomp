typedef unsigned char u8;

struct State {
    char *pActor;       /* 0x00 */
    void *pTarget;       /* 0x04 */
    char pad08[0x10];
    int field_18;         /* 0x18 */
    char pad1c[0x24];
    int field_40;         /* 0x40 */
    int nTimer44;          /* 0x44 */
};

struct Node {
    void *pScene;
    struct State *pState;
    char pad08[0x18];
    signed char bSlot;
};

extern void *Ov107_FindNearestObject(char *actor, int mode);
extern void Ov107_PostTagUpdate(char *actor, int mode, int b);
extern int RandNextScaled(int bound);
extern void SetIndexedSlot(struct Node *node, int slot, void *next);

extern void Ov293_ChaseTick(void);

void Ov293_AiEnterChase(struct Node *node)
{
    struct State *st;
    void *pTarget;
    int mode;

    st = node->pState;
    mode = 2;
    pTarget = Ov107_FindNearestObject(st->pActor, 0);
    st->pTarget = pTarget;
    if (pTarget == 0) {
        st->field_18 = 0x2000;
        *(u8 *)(st->pActor + 0x1c7) = mode;
        SetIndexedSlot(node, node->bSlot, 0);
        return;
    }
    st->field_40 = 0;
    Ov107_PostTagUpdate(st->pActor, mode, 1);
    st->nTimer44 = RandNextScaled(0x5001) + 0x1000;
    SetIndexedSlot(node, node->bSlot, (void *)Ov293_ChaseTick);
}
