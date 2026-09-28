/* Ov023_PollForNextState -- ov023 scene poll: hand back the next state function only once bit 1 of
 * the status halfword at +0x8758c of the scene root is set; until then stay put (0). */
extern int data_ov023_0208a784;
extern void Ov023_LoadScripts(void);

void *Ov023_PollForNextState(void) {
    if ((*(unsigned short *)(*(int *)((char *)&data_ov023_0208a784 + 4) + 0x8758c) & 2) != 0) {
        return (void *)Ov023_LoadScripts;
    }
    return 0;
}
