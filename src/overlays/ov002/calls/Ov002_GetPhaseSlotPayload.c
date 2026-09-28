/* Hand back slot `slot`'s payload, but only while the phase is live and that
 * slot's own bit (0x20 << slot) is raised in the flag word. */
extern int Ov002_Link_IsFlag2(void);

typedef struct {
    unsigned int dwFlags;   /* +0 */
    char pad0004[0x14];
    void *slots[1];         /* +0x18 */
} Ov002TimingConfig;

extern Ov002TimingConfig *data_ov002_0207fa08;

void *Ov002_GetPhaseSlotPayload(int slot) {
    Ov002TimingConfig *ctx = data_ov002_0207fa08;

    if (Ov002_Link_IsFlag2() == 0) {
        return 0;
    }

    if ((ctx->dwFlags & (0x20 << slot)) == 0) {
        return 0;
    }

    return ctx->slots[slot];
}
