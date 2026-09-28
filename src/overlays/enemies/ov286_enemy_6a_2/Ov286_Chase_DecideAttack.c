typedef unsigned char u8;

struct State {
    char *pActor;
    char pad04[0x14];
    void *pTarget;      /* 0x18 */
    char pad1c[0xc];
    int nElapsed28;
};

struct Node {
    void *pScene;
    struct State *pState;
    char pad08[0x18];
    signed char bSlot;
};

extern char *Ov107_FindNearestObject(char *actor, int *pOutDistSq);
extern int FX_Sqrt(int x);
/* Returns long long; the unfoldable `+ (z - z)` below is what makes mwcc
   truncate through `adds r0, r0, #0` the way the ROM does. Do not simplify. */
extern int RandNextScaled();
extern void SetIndexedSlot(struct Node *node, int slot, void *next);

void Ov286_Chase_DecideAttack(struct Node *node)
{
    struct State *st;
    u8 *pActor;
    char *pTarget;
    int nDist;
    int nLimit;
    int z;

    st = node->pState;
    st->pTarget = Ov107_FindNearestObject(st->pActor, &nDist);
    pTarget = st->pTarget;
    if (pTarget == 0) {
        return;
    }

    pActor = (u8 *)st->pActor;
    nDist = FX_Sqrt(nDist) -
            (*(int *)(pTarget + 0x80) + *(int *)(pActor + 0x80));

    if (RandNextScaled(0xc9) + (z - z) == 0) {
        *(u8 *)(st->pActor + 0x1c7) = 4;
        SetIndexedSlot(node, node->bSlot, 0);
        return;
    }
    if (nDist < 0x2000) {
        nLimit = 0x1000 - ((*(u8 *)(st->pActor + 0x19e) << 12) / 10);
        st->nElapsed28 += *(int *)((char *)node->pScene + 0x2c);
        if (st->nElapsed28 < nLimit) {
            return;
        }
        *(u8 *)(st->pActor + 0x1c7) = 4;
        SetIndexedSlot(node, node->bSlot, 0);
        return;
    }
    st->nElapsed28 = 0;
}
