extern void RegisterSeqAndInit(void *a, void *b, int c, int d);
extern void Ov050_ActorCreateSubObjects(int a);
extern int data_ov050_020b75c0;
extern int data_ov050_020b755c;

void Ov050_initTwoEntrySlots(void) {
    int obj = data_ov050_020b75c0;
    int i = 0;
    int puVar5;
    int ibase = obj + 0x2c2c;
    puVar5 = ibase + 0x14;
    *(int *)(obj + 0x2c2c) = 0;
    *(int *)(ibase + 4) = 0;
    do {
        RegisterSeqAndInit((void *)puVar5, &data_ov050_020b755c, 1, *(unsigned char *)(obj + 9) + 7);
        *(int *)(ibase + 0xc) = i;
        i++;
        *(int *)(ibase + 0x10) = 0;
        puVar5 += 0x118;
        ibase += 0x118;
    } while (i < 2);
    Ov050_ActorCreateSubObjects(obj);
}
