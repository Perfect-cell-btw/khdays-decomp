/* Reloads the selected slot's node from its resource, keeping the context's byte at +0x10. */

extern int data_ov022_020b2e78;
extern int Ov002_PollSession(void);
extern int Ov022_GetGlobalPlus14(void);
extern void Ov022_LoadNodeFromResource(int arg0, int arg1);

void func_ov022_02087a70(void) {
    int obj = *(int *)((char *)&data_ov022_020b2e78 + 4);
    int slot;
    int g;
    int save;
    if (*(int *)(obj + 0x10) == 0) return;
    if (Ov002_PollSession() == 0) return;
    slot = *(int *)(*(int *)(obj + 0x10) + 0x20);
    g = Ov022_GetGlobalPlus14();
    save = *(unsigned char *)(g + 0x10);
    Ov022_LoadNodeFromResource(slot, 0);
    *(unsigned char *)(g + 0x10) = save;
}
