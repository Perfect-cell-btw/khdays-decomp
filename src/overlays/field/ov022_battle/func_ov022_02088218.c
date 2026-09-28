typedef struct { int a, b, c; } T3_02088218;
extern int GetEntryField20ByIndex(int arg0);
extern void Actor_SetVecAndSyncChild(unsigned int *arg0, unsigned int *arg1);
extern void Ov022_ResetActorAfterPlace(int *arg0);
void func_ov022_02088218(int arg0, unsigned int *arg1) {
    int *e = (int *)GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    Actor_SetVecAndSyncChild((unsigned int *)e[8], arg1);
    *(T3_02088218 *)(e + 0x123) = *(T3_02088218 *)arg1;
    Ov022_ResetActorAfterPlace(e);
}
