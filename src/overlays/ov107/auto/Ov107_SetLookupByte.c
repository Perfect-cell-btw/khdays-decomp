/* Store byte param_3 at offset param_2 into the buffer pointed to by param_1+0x9c. */
void Ov107_SetLookupByte(int param_1, int param_2, int param_3) {
    *(unsigned char *)(*(int *)(param_1 + 0x9c) + param_2) = (unsigned char)param_3;
}
