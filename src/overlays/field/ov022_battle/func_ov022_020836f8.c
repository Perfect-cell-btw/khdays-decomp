extern void EntityMgr_PopVramState(void);
extern int data_ov022_020b2e60;
extern void func_ov022_02083714(void);

int func_ov022_020836f8(void) {
    EntityMgr_PopVramState();
    *(int *)(*(int *)&data_ov022_020b2e60 + 4) = 0;
    return (int)func_ov022_02083714;
}
