/* Arm or disarm the tracker node for tag 0xc.
 *
 * The node is looked up by tag, given the word the context keeps at 0x69c, and then armed or
 * disarmed with the caller's flag. Arming also runs an extra setup step with 0xf and 0x16.
 *
 * The context pointer is bound before the lookup even though its field is not read until after:
 * the original dereferences the global into the same register that later holds the node, so the
 * two lifetimes never overlap. */

typedef unsigned int u32;

extern char *data_ov002_0207f624;
extern void *Ov002_Ctx_FindActiveEntryByTag(int tag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_6(void *node, u32 value);
extern void Ov002_PositionSubDcHandle_4(void *node, int a, int b);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(void *node, int armed);

void Ov002_SetTagTrackerArmed(int armed) {
    char *ctx = data_ov002_0207f624;
    void *node = Ov002_Ctx_FindActiveEntryByTag(0xc);

    Ov002_Ctx_SetTagTrackerNodeArmed_6(node, *(u32 *)(ctx + 0x69c));
    if (armed != 0) {
        Ov002_PositionSubDcHandle_4(node, 0xf, 0x16);
    }
    Ov002_Ctx_SetTagTrackerNodeArmed_5(node, armed);
}
