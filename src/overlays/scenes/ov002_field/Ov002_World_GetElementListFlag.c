/* Bit 0 of the world element list's flag byte. */

extern int data_ov002_0207f60c;
extern int Ov002_GetBit0OfByte0x2c();

int Ov002_World_GetElementListFlag(void) {
    return Ov002_GetBit0OfByte0x2c(*(int *)&data_ov002_0207f60c + 0xdc);
}
