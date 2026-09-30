/* Ov245_SetNodeMode3 -- set node mode 3 and re-run its layout, ov245 (tail-call to Ov107_PostTagUpdate
 * with the freshly-set mode byte @+0x4d8). */
extern int Ov107_PostTagUpdate(void *node, int mode, int);
int Ov245_SetNodeMode3(char *node) {
    *(signed char *)(node + 0x4d8) = 3;
    return Ov107_PostTagUpdate(node, *(signed char *)(node + 0x4d8), 0);
}
