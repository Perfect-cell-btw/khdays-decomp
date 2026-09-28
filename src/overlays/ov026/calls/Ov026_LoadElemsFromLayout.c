/* For each variable-stride record, build a sprite via Ov026_AddElem (kind-mapped priority) and place it via Ov026_Elem_SetPos. */
extern int Ov026_AddElem(int self, int a, int b, int c, int d, int e, int f, int prio);
extern void Ov026_Elem_SetPos(int self, int handle, int x, int y);
extern unsigned char data_ov026_020910b4;
extern unsigned char data_ov026_020910b0;
void Ov026_LoadElemsFromLayout(int param_1, int param_2) {
    unsigned int n = *(unsigned int *)param_2;
    int p = param_2 + 4;
    unsigned int i;
    for (i = 0; i < n; i++) {
        unsigned int kind = *(unsigned short *)(p + 0x14);
        unsigned char prio = kind >= 0xa ? (&data_ov026_020910b4)[kind - 0xa] : (&data_ov026_020910b0)[kind];
        int handle = Ov026_AddElem(param_1, *(unsigned short *)(p + 6),
            *(unsigned short *)(p + 4), *(unsigned short *)(p + 0xc),
            *(unsigned short *)(p + 0xe), *(short *)(p + 0x10),
            *(short *)(p + 0x12), prio);
        Ov026_Elem_SetPos(param_1, handle, *(short *)(p + 8), *(short *)(p + 0xa));
        p += *(int *)p;
    }
}
