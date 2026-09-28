extern int MsgQueue_Contains(unsigned int arg0);
extern void Ov022_Member_ShowDamage(int i, unsigned short a, unsigned int b, unsigned int c);
extern int data_ov022_020b2ea4;

void func_ov022_02089e20(void) {
    unsigned short *h = (unsigned short *)(*(int *)&data_ov022_020b2ea4 + 0x14);
    unsigned char *b = (unsigned char *)h;
    int i = 0;
    do {
        unsigned int v = h[i + 0x4e];
        if (v != 0xffff && MsgQueue_Contains(v) == 0) {
            Ov022_Member_ShowDamage(i, h[i], b[i + 8], b[i + 0xc]);
            h[i + 0x4e] = 0xffff;
        }
        i = i + 1;
    } while (i < 4);
}
