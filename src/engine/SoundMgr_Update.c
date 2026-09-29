/* Per-frame command dispatcher for the object anchored at data_0204c234, plus the tail
 * maintenance pass over its "active" SlotLink list (base+0xb46e8): each node is either
 * kept spatialised (Sound_UpdateSpatial) or unlinked (ScriptPool_FreeSlot) depending on
 * NNS_SndPlayerCountPlayingSeqByPlayerNo's verdict on the node's index field, then NNS_SndMain() runs.
 *
 * The dispatcher itself is a phase byte at +0xb46fc (0..4) selecting one of four blocks,
 * each of which in turn switches on a queued command id at +0xb479e (0..5) with its
 * parameter byte at +0xb479f. Field names beyond that are honestly unknown: field_6f6/
 * field_6f8/field_6fa are short state slots read/written across the four phases, field_7a0
 * is a value forwarded into SoundMgr_StopBgm/NNS_SndPlayerStopSeq and into the +0xb4700 countdown,
 * and +0xb44c4 is an opaque sub-object passed to several helpers.
 *
 * data_02042124 is a 48-byte slot-kind table living in .rodata (confirmed in
 * build/data_index.json), so the `const` on it is the honest declaration -- and it is also
 * load-bearing for codegen. Without it mwcc cannot prove the table cannot alias the stores
 * made through `base` (a plain char *), and the four temporaries in the cmdId==5 /
 * target>=0 block (table address, loaded kind, the 0xb46f6 offset, the -1 constant) colour
 * differently: the -1 takes r1 and the kind is pushed out to ip. With const, the kind lands
 * in r1 and the -1 in lr, as in the ROM. Nothing else in this function is sensitive to it. */

#include "game/engine.h"

extern char *data_0204c234;
extern void NNS_SndPlayerStopSeq(void *ptr, int arg);
extern int NNS_SndPlayerReadVariable(int *param_1, int param_2, short *param_3);
extern int *SoundMgr_PeekQueued(int i);
extern int NNS_SndArcPlayerStartSeq(void *ptr, int arg);
extern int NNS_SndPlayerWriteVariable(void *obj, int a, int b);
extern void NNS_SndPlayerMoveVolume(void *obj, int param_1, int param_2);
extern int NNS_SndPlayerCountPlayingSeqByPlayerNo(int index);
extern void NNS_SndMain(void);
extern const unsigned char data_02042124[48];

typedef struct SlotLink {
    struct SlotLink *next;
    struct SlotLink *prev;
} SlotLink;

void SoundMgr_Update(void)
{
    char *base = data_0204c234;

    SoundMgr_ExpireRequests();

    switch (*(unsigned char *)(base + 0xb46fc)) {
    case 0:
        if (*(unsigned char *)(base + 0xb47b3) != 0) {
            SoundMgr_PopQueued();
            switch (*(unsigned char *)(base + 0xb479e)) {
            case 1:
            case 2:
            case 4:
            case 5:
                *(short *)(base + 0xb46f8) = -1;
                if (*(unsigned char *)(base + 0xb479e) != 1) {
                    *(unsigned char *)(base + 0xb479e) = 2;
                }
                StoreU16FieldAndRefresh(*(unsigned char *)(base + 0xb479f));
                break;
            case 0:
            case 3:
            default:
                *(unsigned char *)(base + 0xb479e) = 0;
                break;
            }
        }
        break;

    case 3:
        if (*(unsigned char *)(base + 0xb47b3) != 0) {
            short target = *(short *)(base + 0xb46f6);
            unsigned char cmdId;
            unsigned char param;
            int targetKind;

            SoundMgr_PopQueued();
            cmdId = *(unsigned char *)(base + 0xb479e);
            param = *(unsigned char *)(base + 0xb479f);

            switch (cmdId) {
            case 0:
                break;
            case 1:
            case 2:
                *(short *)(base + 0xb46f8) = -1;
                StoreU16FieldAndRefresh(param);
                break;
            case 3:
                *(short *)(base + 0xb46f8) = -1;
                SoundMgr_StopBgm(*(unsigned short *)(base + 0xb47a0));
                break;
            case 4:
                *(short *)(base + 0xb46f8) = -1;
                if (target == param) {
                    break;
                }
                if (target >= 0) {
                    *(short *)(base + 0xb46f6) = -1;
                    NNS_SndPlayerStopSeq(base + 0xb44c4, *(unsigned short *)(base + 0xb47a0));
                    *(int *)(base + 0xb4700) = *(unsigned short *)(base + 0xb47a0);
                    *(unsigned char *)(base + 0xb46fc) = 4;
                } else {
                    StoreU16FieldAndRefresh(param);
                }
                break;
            case 5:
                if (target == param) {
                    break;
                }
                if (target >= 0) {
                    targetKind = data_02042124[target];
                    *(short *)(base + 0xb46f6) = -1;
                    if (targetKind == 1 && data_02042124[param] == 2) {
                        *(short *)(base + 0xb46f8) = target;
                        *(unsigned char *)(base + 0xb479e) = 4;
                        NNS_SndPlayerReadVariable((int *)(base + 0xb44c4), 0, (short *)(base + 0xb46fa));
                    } else if (!(*(short *)(base + 0xb46f8) >= 0 &&
                                 *(short *)(base + 0xb46f8) == param &&
                                 data_02042124[param] == 1)) {
                        *(short *)(base + 0xb46f8) = -1;
                        *(unsigned char *)(base + 0xb479e) = 4;
                    }
                    NNS_SndPlayerStopSeq(base + 0xb44c4, *(unsigned short *)(base + 0xb47a0));
                    *(int *)(base + 0xb4700) = *(unsigned short *)(base + 0xb47a0);
                    *(unsigned char *)(base + 0xb46fc) = 4;
                } else {
                    *(short *)(base + 0xb46f8) = -1;
                    *(unsigned char *)(base + 0xb479e) = 4;
                    StoreU16FieldAndRefresh(param);
                }
                break;
            }
        }
        break;

    case 2:
        switch (*(unsigned char *)(base + 0xb479e)) {
        case 0:
            SoundMgr_PopQueued();
            break;
        case 1: {
            if (SoundMgr_PeekQueued(0) == 0) {
                break;
            }
            SoundMgr_PopQueued();
            {
                unsigned char cmdId = *(unsigned char *)(base + 0xb479e);
                if (cmdId == 2 || cmdId == 4) {
                    unsigned char param = *(unsigned char *)(base + 0xb479f);
                    if (*(short *)(base + 0xb46f6) != param) {
                        StoreU16FieldAndRefresh(param);
                        break;
                    }
                }
                if (cmdId == 3) {
                    *(short *)(base + 0xb46f8) = -1;
                    SoundMgr_StopBgm(*(unsigned short *)(base + 0xb47a0));
                }
            }
            break;
        }
        case 2:
        case 4:
            NNS_SndArcPlayerStartSeq(base + 0xb44c4, *(short *)(base + 0xb46f6));
            NNS_SndPlayerWriteVariable(base + 0xb44c4, 0, 0);
            NNS_SndPlayerMoveVolume(base + 0xb44c4, *(unsigned char *)(base + 0xb46fd), 0);
            *(unsigned char *)(base + 0xb479e) = 0;
            *(unsigned char *)(base + 0xb46fc) = 3;
            break;
        case 3:
            break;
        case 5:
            NNS_SndArcPlayerStartSeq(base + 0xb44c4, *(short *)(base + 0xb46f6));
            NNS_SndPlayerWriteVariable(base + 0xb44c4, 0, *(short *)(base + 0xb46fa));
            NNS_SndPlayerMoveVolume(base + 0xb44c4, *(unsigned char *)(base + 0xb46fd), 0x14);
            *(unsigned char *)(base + 0xb479e) = 0;
            *(unsigned char *)(base + 0xb46fc) = 3;
            break;
        }
        break;

    case 4: {
        int timer = *(int *)(base + 0xb4700);
        if (timer > 0) {
            *(int *)(base + 0xb4700) = timer - 1;
        }
        if (*(int *)(base + 0xb4700) != 0) {
            break;
        }
        {
            switch (*(unsigned char *)(base + 0xb479e)) {
            case 4:
            case 5:
                StoreU16FieldAndRefresh(*(unsigned char *)(base + 0xb479f));
                break;
            default:
                *(unsigned char *)(base + 0xb479e) = 0;
                *(unsigned char *)(base + 0xb46fc) = 0;
                break;
            }
        }
        break;
    }
    }

    {
        SlotLink *node = *(SlotLink **)(base + 0xb46e8);
        while (node != 0) {
            short idx = *(short *)((char *)node + 0x16);
            SlotLink *next = node->next;
            if (NNS_SndPlayerCountPlayingSeqByPlayerNo(idx) == 0) {
                ScriptPool_FreeSlot(node);
            } else {
                Sound_UpdateSpatial((int)node);
            }
            node = next;
        }
    }
    NNS_SndMain();
}
