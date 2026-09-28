/* Request the leave: raise bit 8 of the leave flags at +0x8b64 and report that
 * the request took. A solo machine can always leave; in a session it can only
 * leave once the peer check clears. */
extern int Session_GetLocalPlayerIndex(void);
extern int Ov002_GetRootField8b68Alt(int slot);

typedef struct {
    char pad0000[0x8b64];
    unsigned int dwLeaveFlags;  /* +0x8b64 */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

int Ov002_RequestLeave(void) {
    Ov002RootContext *root = data_ov002_0207fa00;

    {
        int self = Session_GetLocalPlayerIndex();

        if (self == 0 && Ov002_GetRootField8b68Alt(self) != 0) {
            return 0;
        }
    }

    root->dwLeaveFlags |= 1 << 8;
    return 1;
}
