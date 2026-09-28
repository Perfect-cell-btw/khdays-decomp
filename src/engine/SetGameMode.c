/* Stores the byte argument into a global. */

extern unsigned char data_0204c058;

void SetGameMode(int arg0)
{
    *(unsigned char *)&data_0204c058 = (unsigned char)arg0;
}
