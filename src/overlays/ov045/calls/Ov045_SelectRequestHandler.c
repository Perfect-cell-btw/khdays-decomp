extern int data_ov045_020b4c20;
extern void Ov045_HoverStep(void);
extern void Ov045_DescentStep(void);

void *Ov045_SelectRequestHandler(int self, int a) {
    int base = *(int *)&data_ov045_020b4c20 + 0xdf0 + 0x2000;
    void *cb = 0;
    if (a != 0x21) {
        if (a == 0x22) cb = (void *)&Ov045_HoverStep;
    } else {
        void (*fn)(int, int) = *(void (**)(int, int))(self + 0x664);
        if (*(int *)(base + 0x114) != 0) {
            fn(self, 0x30);
        } else {
            fn(self, 0x2f);
        }
        cb = (void *)&Ov045_DescentStep;
    }
    return cb;
}
