/* Copies the current 8-byte source block into the buffer; returns the buffer, or 0 when there is no
 * source. */

extern void *data_ov008_02090f14;
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);

void *Ov008_CopySourceBlock(void *dst)
{
    if (data_ov008_02090f14 == 0) {
        return 0;
    }

    MI_CpuCopy8(data_ov008_02090f14, dst, 8);
    return dst;
}
