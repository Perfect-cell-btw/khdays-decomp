/* Copies the eight-byte point (+0x1c) into the output and returns it. */

extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);

void *Ov008_GetTouchSample(void *src, void *dst)
{
    MI_CpuCopy8((char *)src + 0x4a44, dst, 8);
    return dst;
}
