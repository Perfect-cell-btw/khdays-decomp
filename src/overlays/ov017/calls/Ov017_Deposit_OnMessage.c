/* Deposit class pfnMessage: on message 1 sets the state (+0x4da) to 2. */

void Ov017_Deposit_OnMessage(void *self, unsigned char *value)
{
    if (*value == 1) {
        *(unsigned char *)((char *)self + 0x4da) = 2;
    }
}
