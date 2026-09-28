/* Return the object pointer stored at +0x9634 of the ov025 menu context. Ov025_GetCtxObject9634 is
 * the same field in ov025 -- the two overlays share this context layout. */

extern int data_ov025_020b5744;

int Ov025_GetCtxObject9634(void) {
    return *(int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9634);
}
