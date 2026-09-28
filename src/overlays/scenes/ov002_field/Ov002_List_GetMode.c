/* The object list's mode byte. */

extern int data_ov002_0207fa20;

int Ov002_List_GetMode(void) {
    return *(signed char *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + 0x260);
}
