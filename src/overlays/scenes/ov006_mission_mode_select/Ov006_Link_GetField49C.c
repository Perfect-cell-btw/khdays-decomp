/* Returns a word at a fixed offset of the object a global points to. */

extern int data_ov006_020565e4;
int Ov006_Link_GetField49C(void) {
    return *(int *)(*(int *)&data_ov006_020565e4 + 0x49c);
}
