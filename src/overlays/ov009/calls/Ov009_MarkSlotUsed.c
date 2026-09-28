extern char *data_ov009_020563e4[];
extern int Ov009_MapCodeToSlotIndex(void);

void Ov009_MarkSlotUsed(void)
{
    int index = Ov009_MapCodeToSlotIndex();

    if (index != -1) {
        *(unsigned char *)(data_ov009_020563e4[1] + 0x963c) |= 1 << index;
    }
}
