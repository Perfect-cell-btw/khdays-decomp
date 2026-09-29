/* Enables or disables sound effects: Slot_Spawn starts none while the byte at +0xb47b5 of the
 * sound manager is clear. */

extern int data_0204c234;

void SoundMgr_SetSeEnabled(char enabled) {
    *(char *)(*(int *)&data_0204c234 + 0xb47b5) = enabled;
}
