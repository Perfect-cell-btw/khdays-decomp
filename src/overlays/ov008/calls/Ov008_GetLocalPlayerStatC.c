extern int Ov008_GetLocalPlayerCharacter(void);
extern unsigned char data_ov008_0208f854[];

int Ov008_GetLocalPlayerStatC(void)
{
    int index = Ov008_GetLocalPlayerCharacter();

    if (index < 0) {
        return 0;
    }

    if (index >= 0x14) {
        return 0;
    }

    return *(unsigned short *)(data_ov008_0208f854 + index * 6);
}
