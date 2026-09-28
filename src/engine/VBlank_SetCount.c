/* Sets the VBlank count (the word at data_027e0088 in DTCM); Scene_Leave restores it on the way out
 * of a scene. Its old name (srand) was a shape match. */

extern int data_027e0088;

void VBlank_SetCount(int count) {
    data_027e0088 = count;
}
