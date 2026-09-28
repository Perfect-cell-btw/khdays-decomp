/* Read the field at (&data_ov009_020563e4 + 4). */
extern int data_ov009_020563e4;
int Ov009_GetContext(void) {
    return *(int *)((char *)&data_ov009_020563e4 + 4);
}
