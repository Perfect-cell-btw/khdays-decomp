/* Returns a word at a fixed offset of the object a global points to. */

extern int data_ov002_0207fa14;

int Ov002_Event_GetField18(void) {
    return *(int *)(*(int *)&data_ov002_0207fa14 + 0x18);
}
