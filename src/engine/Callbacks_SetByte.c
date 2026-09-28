/* Stores the byte argument into a global. */

extern unsigned char data_0204bd84;

void Callbacks_SetByte(int arg0)
{
    *(unsigned char *)&data_0204bd84 = (unsigned char)arg0;
}
