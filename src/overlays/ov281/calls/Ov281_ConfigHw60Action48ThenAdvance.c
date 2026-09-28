/* Configures actor hw60 high-byte flags, clears linked subobject flags, starts action 0x48, clears
 * a state slot, then advances to the next node callback. */

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov281_CompleteAction48Windup(void);

struct ov281_Hw60 {
    unsigned short lo : 8;
    unsigned short hi : 8;
};

struct ov281_LowByteFlags {
    unsigned bits : 8;
};

void Ov281_ConfigHw60Action48ThenAdvance(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10);
    }

    ((struct ov281_Hw60 *)(*state + 0x60))->hi &= ~0xc;
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct ov281_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, *state + 0x74);
    state[6] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov281_CompleteAction48Windup);
}
