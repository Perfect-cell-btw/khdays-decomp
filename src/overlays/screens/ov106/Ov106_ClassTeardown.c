/* Class pfnMethod: clears the class's global instance pointer. */

/* Clear the global word at data_ov106_020b8b68. */
extern int data_ov106_020b8b68;
void Ov106_ClassTeardown(void) {
    *(int *)&data_ov106_020b8b68 = 0;
}
