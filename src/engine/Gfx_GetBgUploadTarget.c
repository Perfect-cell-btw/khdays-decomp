/* Returns the GFX upload target of background index 0-7 (data_02041e6c: 4-7 for the main
 * engine's BG0-3, 20-23 for the sub engine's). */

extern int data_02041e6c;

int Gfx_GetBgUploadTarget(int index) {
    return ((int *)&data_02041e6c)[index];
}
