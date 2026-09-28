extern void RegisterSeqAndInit(void *a, void *b, int c, int d);
extern void Ov070_ActorCreateSubObjects(int a);
extern int data_ov070_020b9ca0;
extern int data_ov070_020b9c3c;

void Ov070_initTwoEntrySlots(void) {
    int obj = data_ov070_020b9ca0;
    int i = 0;
    int puVar5;
    int ibase = obj + 0x2c2c;
    puVar5 = ibase + 0x14;
    *(int *)(obj + 0x2c2c) = 0;
    *(int *)(ibase + 4) = 0;
    do {
        RegisterSeqAndInit((void *)puVar5, &data_ov070_020b9c3c, 1, *(unsigned char *)(obj + 9) + 7);
        *(int *)(ibase + 0xc) = i;
        i++;
        *(int *)(ibase + 0x10) = 0;
        puVar5 += 0x118;
        ibase += 0x118;
    } while (i < 2);
    Ov070_ActorCreateSubObjects(obj);
}
