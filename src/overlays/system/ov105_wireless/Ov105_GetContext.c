/* Read the field at (&data_ov105_020bfa20 + 4). */
extern int data_ov105_020bfa20;
int Ov105_GetContext(void) {
    return *(int *)((char *)&data_ov105_020bfa20 + 4);
}
