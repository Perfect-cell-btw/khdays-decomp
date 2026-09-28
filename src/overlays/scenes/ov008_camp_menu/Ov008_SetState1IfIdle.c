/* Sets the menu state when it is idle (no pending transition at +0x158 or +0x180). */

void Ov008_SetState1IfIdle(char *obj) {
    if (*(int *)(obj + 0x158) == 0 && *(int *)(obj + 0x180) == 0) {
        *(int *)(obj + 8) = 1;
    }
}
