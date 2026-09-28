/* Tail-call CARD_IdentifyBackup with the constant 0x1001. */
extern int CARD_IdentifyBackup(int arg);
int Ov000_IdentifyBackup(void) {
    return CARD_IdentifyBackup(0x1001);
}
