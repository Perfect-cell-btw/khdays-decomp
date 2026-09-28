/* Stores a fixed value into a field of a global object. */

extern int data_ov012_0205cb20;

void Ov012_SetGlobalByte8be1To1(void) {
    *(unsigned char *)(data_ov012_0205cb20 + 0x8be1) = 1;
}
