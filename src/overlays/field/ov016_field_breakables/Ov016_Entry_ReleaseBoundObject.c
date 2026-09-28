/* Tail-call ReleaseField74AndCleanup on the sub-object at param_1+0x1b0. */
extern int ReleaseField74AndCleanup(void *obj);
int Ov016_Entry_ReleaseBoundObject(int param_1) {
    return ReleaseField74AndCleanup((void *)(param_1 + 0x1b0));
}
