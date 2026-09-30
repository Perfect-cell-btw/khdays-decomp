#pragma thumb on
/* Sibling of Entity_Register; second helper is ClearFlag20InitChildAndSyncTransform2. */

extern int gEntityMgr;
extern void Actor_ArmWithMessage(void *obj, int a, int b, void *c, int d);
extern int ClearFlag20InitChildAndSyncTransform2(void *field, int p2, int p3, int p4);

int Actor_StartMotion(void *obj, int p2, int p3, int p4) {
    if ((*(unsigned char *)((char *)obj + 8) & 1) == 0) {
        Actor_ArmWithMessage(obj, 0, 0, 0, 1);
    }
    if (ClearFlag20InitChildAndSyncTransform2((char *)obj + 0xc, p2, p3, p4) != 0) {
        *(unsigned char *)((char *)obj + 0xb) = *(unsigned char *)(gEntityMgr + 0xa4d0);
        *(unsigned char *)((char *)obj + 9) = (unsigned char)p4;
        *(unsigned char *)((char *)obj + 8) |= 4;
        return 1;
    }
    return 0;
}
