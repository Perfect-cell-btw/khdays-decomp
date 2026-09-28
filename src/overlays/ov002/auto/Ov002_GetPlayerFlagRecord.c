/* 0x14-byte player flag record idx. */

extern int data_ov002_0207f9a0;

int Ov002_GetPlayerFlagRecord(int arg0) {
    return (int)&data_ov002_0207f9a0 + arg0 * 0x14;
}
