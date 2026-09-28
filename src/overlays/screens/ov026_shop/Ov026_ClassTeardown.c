/* Class pfnMethod: clears the instance pointer. */

/* Clear the ov026 global word. */
extern int data_ov026_02091360;
void Ov026_ClassTeardown(void) {
    data_ov026_02091360 = 0;
}
