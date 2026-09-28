/* Message handler: on message 1 sets the state (+0x134) to 2. */

void Ov014_OnMessage(void *self, unsigned char *value)
{
    if (*value == 1) {
        *(unsigned char *)((char *)self + 0x134) = 2;
    }
}
