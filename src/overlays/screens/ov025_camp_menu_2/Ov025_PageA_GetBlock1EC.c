/* Returns the address of page A's block at +0x1ec. */

extern int Ov025_GetPageA(void);

int Ov025_PageA_GetBlock1EC(void)
{
    return Ov025_GetPageA() + 0x1ec;
}
