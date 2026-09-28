/* Choose the ov106 screen layers: while field 0x248c is clear, layer 0 shows unless +0x8e48 is set and
 * layer 1 hides (plus layer 1 of the second group); otherwise the layer selected by +0x8e48 shows and
 * the other hides. */
extern char *data_ov106_020b8b60;
extern int GameState_IsFlagSet(int flag);
extern void Ov002_SetSlotFlag1(int index, int flag);
extern void Ov002_FireSlotHook(int nA, int nB);

void Ov106_SelectScreenLayers(void)
{
    if (GameState_IsFlagSet(0x248c) == 0) {
        Ov002_SetSlotFlag1(0, *(int *)(data_ov106_020b8b60 + 0x8e48) == 0);
        Ov002_SetSlotFlag1(1, 0);
        Ov002_FireSlotHook(1, 0);
    } else {
        Ov002_SetSlotFlag1(*(int *)(data_ov106_020b8b60 + 0x8e48) != 0, 1);
        Ov002_SetSlotFlag1(*(int *)(data_ov106_020b8b60 + 0x8e48) == 0, 0);
    }
}
