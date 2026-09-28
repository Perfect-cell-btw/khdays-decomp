/* Resource callback: blits the entry's tile rectangle. */

extern int Ov009_BlitTileRect(int a, int b);
int Ov009_ResourceNodeCallback(int param_1) {
    return Ov009_BlitTileRect(param_1, 0);
}
