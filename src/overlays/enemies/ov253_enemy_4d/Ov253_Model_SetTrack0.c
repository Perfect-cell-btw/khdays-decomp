/* Ov253_Model_SetTrack0 -- forward a 16-bit value to the node's owner, ov253 (tail-call to
 * SetSubitemState over the owner @+0x38c, passing (short)val and flags). */
extern int SetSubitemState(void *owner, int, int val, int flags);
int Ov253_Model_SetTrack0(char *node, int val, int flags) {
    return SetSubitemState(*(void **)(node + 0x38c), 0, (short)val, flags);
}
