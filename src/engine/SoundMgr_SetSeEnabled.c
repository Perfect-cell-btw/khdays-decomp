/* Enables or disables sound effects: Slot_Spawn starts none while the byte at +0xb47b5 of the
 * sound manager is clear. */

extern int gSoundMgr;

void SoundMgr_SetSeEnabled(char enabled) {
    *(char *)(*(int *)&gSoundMgr + 0xb47b5) = enabled;
}
