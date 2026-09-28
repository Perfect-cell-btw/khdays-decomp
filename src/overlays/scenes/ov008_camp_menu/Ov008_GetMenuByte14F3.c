extern unsigned char *Ov008_GetMenuContext(void);

int Ov008_GetMenuByte14F3(void)
{
    return Ov008_GetMenuContext()[0x14f3];
}
