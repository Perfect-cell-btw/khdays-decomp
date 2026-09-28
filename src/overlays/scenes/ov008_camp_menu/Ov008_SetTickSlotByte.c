/* Stores the mission slot byte (also into the screen flags for the host). */

extern char *data_ov008_02090f24;
extern int func_01ff8128(void);

void Ov008_SetTickSlotByte(int value)
{
    *(unsigned char *)(data_ov008_02090f24 + 0x42a) = value;

    if (func_01ff8128() == 0) {
        *(unsigned char *)(data_ov008_02090f24 + func_01ff8128() + 0x48e) = value;
    }
}
