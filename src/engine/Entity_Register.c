#pragma thumb on
/* Register obj on entity system: lazily init (Actor_ArmWithMessage) if state bit 0 is
 * clear, run ClearFlag20InitChildAndSyncTransform on obj+0xc; on success stamp obj[0xb] from a global
 * table byte, store p4 in obj[9], set state bit 4, return 1 (else 0). */

extern int data_0204c208;
extern void Actor_ArmWithMessage(void *obj, int a, int b, void *c, int d);
extern int ClearFlag20InitChildAndSyncTransform(void *field, int p2, int p3, int p4);

int Entity_Register(void *obj, void *pP2, int p3, int p4) {
    int p2 = (int)pP2;
    if ((*(unsigned char *)((char *)obj + 8) & 1) == 0) {
        Actor_ArmWithMessage(obj, 0, 0, 0, 1);
    }
    if (ClearFlag20InitChildAndSyncTransform((char *)obj + 0xc, p2, p3, p4) != 0) {
        *(unsigned char *)((char *)obj + 0xb) = *(unsigned char *)(data_0204c208 + 0xa4d0);
        *(unsigned char *)((char *)obj + 9) = (unsigned char)p4;
        *(unsigned char *)((char *)obj + 8) |= 4;
        return 1;
    }
    return 0;
}
