/* Takes the ROM resource lock and then the card bus. */
extern void CARDi_LockResource(int id, int resource);
extern void OS_LockCard(int id);

void CARD_LockRom(int id) {
    CARDi_LockResource(id, 1);
    OS_LockCard(id);
}
