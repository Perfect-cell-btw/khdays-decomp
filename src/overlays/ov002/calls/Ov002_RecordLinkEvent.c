/* Record a link event in the byte at +0x8dc2. Event 0x1a replaces it wholesale
 * with the layer's own status; event 0x19 raises just the reporting peer's bit.
 * Anything else is ignored. */
extern int GetGlobalU16At6(void);

typedef struct {
    char pad0000[0x8dc2];
    unsigned char bLinkStatus;      /* +0x8dc2 */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

void Ov002_RecordLinkEvent(int event, int peer) {
    Ov002RootContext *root = data_ov002_0207fa00;

    if (event == 0x1a) {
        root->bLinkStatus = (unsigned char)GetGlobalU16At6();
        return;
    }

    if (event != 0x19) {
        return;
    }

    root->bLinkStatus |= 1 << peer;
}
