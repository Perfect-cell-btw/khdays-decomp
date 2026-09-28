extern unsigned char Ov002_GetRootField8bad(void);
extern void Ov002_World_SetByte8BAD(int arg0);
extern int data_ov022_020b2e60;

void func_ov022_02083d24(void) {
    int *g = &data_ov022_020b2e60;
    *(unsigned short *)*g &= ~2;
    *(unsigned char *)(*g + 0x3e) = Ov002_GetRootField8bad();
    Ov002_World_SetByte8BAD(0);
    *(int *)(*g + 4) = 4;
}
