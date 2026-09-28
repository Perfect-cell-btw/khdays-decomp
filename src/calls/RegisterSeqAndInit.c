extern int SND_RegisterSeq();
extern void ModelInst_Init();

void RegisterSeqAndInit(int this_, int arg1, int arg2, int arg3) {
    *(int *)(this_ + 0x74) = SND_RegisterSeq(arg1, arg3);
    ModelInst_Init(this_, arg2, 1, arg3);
}
