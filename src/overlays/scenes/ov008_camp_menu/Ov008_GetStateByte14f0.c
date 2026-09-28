/* Returns an indexed byte of the menu context (+0x14f0). */

extern char *Ov008_GetMenuContext(void);

int Ov008_GetStateByte14f0(int offset)
{
    return (unsigned char)*(Ov008_GetMenuContext() + offset + 0x14f0);
}
