/* Sets the attack state byte (+0x114) to 5. */

void Ov052_SetState5(void *unused, void *self)
{
    *(unsigned char *)((char *)self + 0x114) = 5;
}
