/* Ov023_FlushTextBox -- flush the ov023 text box unless it is already closing (bit 3 of the
 * status halfword at +0x8758c). The box object itself is at +0x4b88 of the scene root. */
extern void SetWordAt0x588To1(void *p);
extern int data_ov023_0208a784;

void Ov023_FlushTextBox(void) {
    char *base = (char *)*(int *)((char *)&data_ov023_0208a784 + 4);
    if ((*(unsigned short *)(base + 0x8758c) & 8) == 0) {
        SetWordAt0x588To1(base + 0x4b88);
    }
}
