/* Ends the current step (installs no handler). */

/* Twin of Ov238_AiEndStep. */
extern int SetIndexedSlot(int a, int b, int c);
int Ov252_AiEndStep(int param_1) {
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
