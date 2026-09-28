/* Allocates and configures the character's effect emitter: takes a channel block and publishes its
 * fixed parameters (speed, lifetime, ranges), enabling the extra flag when the owner's slot option
 * is set. */

extern int NNSi_FndAllocFromDefaultExpHeap(int size);
extern void Ov022_TakeChannelBlock(int a, int b, int c);
extern int Slot_EvalPackedParam(int a, int b);
extern void Ov022_PublishGroupUpdateFixed(int a, int b, void *c, void *d);
extern int data_ov075_020b9df8;

typedef struct {
    int f00;
    int f04;
    char pad08[2];
    unsigned short f0a;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    char pad3c[0x4c - 0x3c];
    unsigned char f4c;
    char pad4d[3];
} Params;

void Ov075_AllocAndConfigureEmitter(int self) {
    Params p;
    *(int *)(self + 0x2644) = NNSi_FndAllocFromDefaultExpHeap(0x90);
    Ov022_TakeChannelBlock(*(int *)(self + 0x2644), 0, 1);
    p.f00 = 5;
    p.f04 = 0;
    p.f0a = 0x19a;
    p.f0c = 0xa00;
    p.f10 = 0xc80;
    p.f14 = 0xa000;
    p.f18 = 0x1e000;
    p.f24 = 0x120;
    p.f20 = 0x7fffffff;
    p.f1c = 0;
    p.f28 = 0;
    p.f30 = 0x300;
    p.f2c = 0x100;
    p.f34 = 0x100;
    p.f38 = 4;
    p.f4c = 8;
    if (Slot_EvalPackedParam(*(unsigned char *)(self + 9), 0x30) != 0) {
        p.f00 |= 1;
    }
    Ov022_PublishGroupUpdateFixed(*(int *)(self + 0x2644), self, &data_ov075_020b9df8, &p);
}
