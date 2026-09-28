/* Spawns an effect at a position when the current sub-object belongs to the local player's group.
 */

extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(unsigned int arg0);
extern void Slot_Spawn(unsigned int arg0, unsigned int arg1, unsigned int *arg2, int arg3);

void func_ov022_0208acdc(int arg0, unsigned int *arg1, unsigned int arg2) {
    if (*(int *)(arg0 + 0xc) < 0) {
        return;
    }
    if (*(char *)(*(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18) + 0x110) !=
        Ov022_GetEntryField66(QueryActiveStateOrDelegate())) {
        return;
    }
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == -1) {
        return;
    }
    Slot_Spawn(*(unsigned int *)(arg0 + 0x10), arg2, arg1, 0);
}
