struct ov008_size12_entry {
    unsigned char _pad[0x12];
};

extern struct ov008_size12_entry data_ov008_0209051c[];
struct ov008_size12_entry *Ov008_GetPageTableEntry(unsigned int index)
{
    if (index >= 3) {
        return 0;
    }
    return &data_ov008_0209051c[index];
}
