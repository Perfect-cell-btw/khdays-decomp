/* Initialises the character's effect record: clears its states, registers its sequence for the
 * owner's palette slot and builds the emitter descriptor. */

extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov083_BuildEmitterDescriptor(int p);
extern int gOv083ZexionLiE1PackPath;

void Ov083_InitActorTwoRegionsAndForward(int this_) {
    char *a = (char *)(this_ + 0x2000);
    char *b = (char *)(this_ + 0x2df0);
    *(unsigned char *)(a + 0xdf0) = 0;
    *(int *)(b + 0x114) = 0;
    RegisterSeqAndInit((int)(b + 4), (int)&gOv083ZexionLiE1PackPath, 1, *(unsigned char *)(this_ + 9) + 7);
    Ov083_BuildEmitterDescriptor(this_);
}
