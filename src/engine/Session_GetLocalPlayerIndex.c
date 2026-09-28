/* Returns the local player's index in the active wireless session, or 0 outside a session. */

extern int Session_IsActive(void *p);
extern unsigned char *data_0204c228;

unsigned int Session_GetLocalPlayerIndex(void)
{
    unsigned char *p = data_0204c228;
    if (p != 0 && Session_IsActive(&data_0204c228) != 0) {
        return *(unsigned short *)(p + 0x22);
    }
    return 0;
}
