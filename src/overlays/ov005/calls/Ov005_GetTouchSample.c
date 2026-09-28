/* Ov005_GetTouchSample -- copy the entry's 8-byte key into `dst`, ov005 (from @+0x4a44);
 * returns dst. */
extern void MI_CpuCopy8(void *src, void *dst, int size);
void *Ov005_GetTouchSample(char *obj, void *dst) {
    MI_CpuCopy8(obj + 0x4a44, dst, 8);
    return dst;
}
