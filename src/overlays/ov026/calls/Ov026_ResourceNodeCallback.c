/* Tail-call Ov026_BlitQueuedImage with flag 0. */
extern int Ov026_BlitQueuedImage(int a, int b);
int Ov026_ResourceNodeCallback(int param_1) {
    return Ov026_BlitQueuedImage(param_1, 0);
}
