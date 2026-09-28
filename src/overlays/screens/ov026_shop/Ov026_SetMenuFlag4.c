/* Set bit 2 of the word pointed to by the ov026 global pointer. */
extern int data_ov026_02091360;
void Ov026_SetMenuFlag4(void) {
    *(int *)data_ov026_02091360 |= 4;
}
