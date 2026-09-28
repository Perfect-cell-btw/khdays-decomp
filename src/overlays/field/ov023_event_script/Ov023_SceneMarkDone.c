/* Set bit 4 of the u16 pointed to by the ov023 global pointer. */
extern int data_ov023_0208a780;
void Ov023_SceneMarkDone(void) {
    *(unsigned short *)data_ov023_0208a780 |= 0x10;
}
