/* Store into entry `i` of the 32-word array at +0x17c of the ov002 module. The read side is
 * Ov002_GetModuleSlot; Ov002_SceneEnter clears the whole 0x80-byte block at construction. */

extern int data_ov002_0207fa20;

void Ov002_SetModuleSlot(int arg0, int arg1) {
    *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + arg0 * 4 + 0x17c) = arg1;
}
