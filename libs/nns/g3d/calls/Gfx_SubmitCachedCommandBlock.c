/* Submit the cached command block at data_02047394 -- its first word is the packed command, the
 * following 0x34 words the parameters -- then clear the two dirty bits at +0xd4. */

extern void GX_SendFifoWords(unsigned int cmd, const void *src, unsigned int words);

struct Gfx0201571c {
    unsigned int cmd;       /* +0x00 */
    char _4[0xd0];
    unsigned int field_d4;  /* +0xd4 */
};

extern struct Gfx0201571c data_02047394;

void Gfx_SubmitCachedCommandBlock(void)
{
    unsigned int *p = (unsigned int *)&data_02047394;
    GX_SendFifoWords(*p, p + 1, 0x34);
    data_02047394.field_d4 &= ~1u;
    data_02047394.field_d4 &= ~2u;
}
