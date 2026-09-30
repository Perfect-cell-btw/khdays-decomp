/* Set obj+0x4c to 1 if any active game slot (1..0x276) is currently flagged in the shared state
 * bitmap at gGameState[+0x810]; otherwise leave it 0. */
extern int Ov025_IsGridItemEligible(int slot);
extern unsigned char *gGameState;

void Ov025_MarkAnyActiveSlot(int obj) {
    int i;
    *(int *)(obj + 0x4c) = 0;
    i = 1;
    do {
        if (Ov025_IsGridItemEligible(i) != 0 && gGameState[i + 0x810] != 0) {
            *(int *)(obj + 0x4c) = 1;
            return;
        }
        i++;
    } while (i < 0x277);
}
