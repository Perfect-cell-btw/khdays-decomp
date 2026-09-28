/* Frees the menu's four fonts. */

extern void FreeFieldAt8();
extern int data_ov025_020b5744;

void Ov025_ResetFourChannels(void) {
    FreeFieldAt8(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9680);
    FreeFieldAt8(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x968c);
    FreeFieldAt8(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9698);
    FreeFieldAt8(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x96a4);
}
