/* Class pfnMethod: clears the class's global instance pointer. */

/* Clear the global word at data_ov023_0208a7c0. */
extern int data_ov023_0208a7c0;
void Ov023_ClassTeardown(void) {
    *(int *)&data_ov023_0208a7c0 = 0;
}
