struct dev {
    unsigned char _pad[0x4a7c];
    unsigned int enable : 1;
};

void Ov008_SetControlBit0AtA7C(int base, int flag)
{
    ((struct dev *)base)->enable = (flag != 0);
}
