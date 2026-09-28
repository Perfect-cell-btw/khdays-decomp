/* Read the field at (*(&data)) + 0x49c. */
extern int data_ov006_020565e4;
int Ov006_Link_GetField49C(void) {
    return *(int *)(*(int *)&data_ov006_020565e4 + 0x49c);
}
