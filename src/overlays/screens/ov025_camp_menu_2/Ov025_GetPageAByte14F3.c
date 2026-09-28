/* Returns page A's byte at +0x14f3. */

extern char *Ov025_GetPageA(void);
unsigned char Ov025_GetPageAByte14F3(void)
{
    return *(unsigned char *)(Ov025_GetPageA() + 5363);
}
