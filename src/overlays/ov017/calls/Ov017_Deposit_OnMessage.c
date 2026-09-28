void Ov017_Deposit_OnMessage(void *self, unsigned char *value)
{
    if (*value == 1) {
        *(unsigned char *)((char *)self + 0x4da) = 2;
    }
}
