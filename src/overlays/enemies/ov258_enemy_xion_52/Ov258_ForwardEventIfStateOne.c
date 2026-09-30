extern void Ov258_SetPartParamsAndQueue2(int target, int a, int b, int c);
/* If the object is in state 1 (obj+0x50), forward (a,b,c) to the sub-target (obj+0x214) handler. */
void Ov258_ForwardEventIfStateOne(int obj, int a, int b, int c) {
    if (*(int *)(obj + 0x50) != 1) {
        return;
    }
    Ov258_SetPartParamsAndQueue2(*(int *)(obj + 0x214), a, b, c);
}
