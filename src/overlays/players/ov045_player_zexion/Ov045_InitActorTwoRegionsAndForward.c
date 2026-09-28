/* Initialises the actor's extra model region and creates its sub-object. */

extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov045_CreateSubObject(int p);
extern int data_ov045_020b4bf4;

void Ov045_InitActorTwoRegionsAndForward(int this_) {
    char *a = (char *)(this_ + 0x2000);
    char *b = (char *)(this_ + 0x2df0);
    *(unsigned char *)(a + 0xdf0) = 0;
    *(int *)(b + 0x114) = 0;
    RegisterSeqAndInit((int)(b + 4), (int)&data_ov045_020b4bf4, 1, *(unsigned char *)(this_ + 9) + 7);
    Ov045_CreateSubObject(this_);
}
