/* Return entry `i` of the 32-word array at +0x17c of the ov002 module. That array is the 0x80-byte
 * block Ov002_SceneEnter clears at construction, which is what fixes its extent. */

extern int data_ov002_0207fa20;

int Ov002_GetModuleSlot(int arg0) {
    return *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + arg0 * 4 + 0x17c);
}
