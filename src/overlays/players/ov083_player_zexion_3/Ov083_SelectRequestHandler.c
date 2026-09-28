/* Special-attack request handler: 0x21 sends the attack command for the variant and returns the
 * descent step; 0x22 returns the hover step. */

extern int data_ov083_020b9b00;
extern void Ov083_HoverStep(void);
extern void Ov083_DescentStep(void);

void *Ov083_SelectRequestHandler(int self, int a) {
    int base = *(int *)&data_ov083_020b9b00 + 0xdf0 + 0x2000;
    void *cb = 0;
    if (a != 0x21) {
        if (a == 0x22) cb = (void *)&Ov083_HoverStep;
    } else {
        void (*fn)(int, int) = *(void (**)(int, int))(self + 0x664);
        if (*(int *)(base + 0x114) != 0) {
            fn(self, 0x30);
        } else {
            fn(self, 0x2f);
        }
        cb = (void *)&Ov083_DescentStep;
    }
    return cb;
}
