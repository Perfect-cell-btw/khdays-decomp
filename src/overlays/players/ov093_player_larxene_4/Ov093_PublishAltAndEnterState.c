/* Begins the special attack: for the local player sets bit 16 of the two 64-bit flag words, records
 * the variant and switches to state 0x22 for the alternate variant or 0x21 otherwise. */

extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int *self, int state);
extern int data_ov093_020bc3c0;

int Ov093_PublishAltAndEnterState(int *self, int alt) {
    char *blk = (char *)(*(int *)&data_ov093_020bc3c0 + 0x2c + 0x2c00);
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    *(int *)(blk + 0x114) = alt;
    if (alt != 0) {
        return Ov022_ActorSetState(self, 0x22);
    }
    return Ov022_ActorSetState(self, 0x21);
}
