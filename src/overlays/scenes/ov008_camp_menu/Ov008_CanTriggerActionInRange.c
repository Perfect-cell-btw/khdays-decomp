/* Whether the entry's action can trigger at the value: the entry is not disabled (+0x23), the value
 * lies in its range (+6..+8), and the game-state flag its kind names (+0x15) is set when it has
 * one. */

extern int GameState_GetField(int arg0, int arg1);

int Ov008_CanTriggerActionInRange(int entry, unsigned int value) {
    int kind;

    if (*(unsigned char *)(entry + 0x23) != 0) return 0;
    if (*(unsigned short *)(entry + 6) > value) return 0;
    if (*(unsigned short *)(entry + 8) < value) return 0;

    kind = *(unsigned char *)(entry + 0x15);
    if (kind != 0) {
        int enabled;
        kind--;
        kind = (int)((char *)0 + kind);
        kind = (unsigned int)(kind << 0x10) >> 0xf;
        kind += 0x379f;
        enabled = (unsigned int)GameState_GetField(kind, 2) >= 1;
        if (enabled == 0) return 0;
    }

    return 1;
}
