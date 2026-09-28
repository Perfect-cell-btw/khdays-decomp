/* Allocate the size-0x58 render instance for this actor (kind 0x64, handler 020cd464),
 * back-link it to the actor and store it at (param_1)+0x214. */
extern int CreateRegistryEntry(int a, int b, int c, void *handler, int e, void *out);
extern void Ov274_EnterMoveState(void);
void Ov274_CreateRegistryEntryAndLink(int param_1) {
    int *out;
    CreateRegistryEntry(*(int *)(param_1 + 0x3c), 0x64, 0x58, (void *)&Ov274_EnterMoveState, 0, &out);
    *out = param_1;
    *(int *)(param_1 + 0x214) = (int)out;
}
