/* Stores the byte argument into a global. */

extern unsigned char gObjSystem;

void SetGameMode(int arg0)
{
    *(unsigned char *)&gObjSystem = (unsigned char)arg0;
}
