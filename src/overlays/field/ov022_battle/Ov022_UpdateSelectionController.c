/* Updates the lock-on label when the selected candidate changes: shows its entry label (or hides
 * it) and marks it as seen. */

#include "nitro/types.h"

typedef struct Ov022Candidate {
    char pad_0000[0x19c];
    u8 selectionId19c;
    char pad_019d[0x0f];
    u16 flags1ac;
    char pad_01ae[0x6a];
    u16 value218;
    u16 value21a;
} Ov022Candidate;

typedef struct Ov022SelectionController {
    u32 flags0;
    u32 selectionFlags;
    int type;
    Ov022Candidate *typeOneCandidate;
    void *node;
    Ov022Candidate *lastTypeOneCandidate;
} Ov022SelectionController;

typedef struct Ov022SelectionMarkOwner {
    char pad_0000[0x810];
    u8 mark810;
} Ov022SelectionMarkOwner;

extern u8 data_0204be04;
extern u8 *data_0204be18;

extern Ov022SelectionController *NNSi_FndGetCurrentRootHeap(void);
extern void func_ov022_020847f0(void);
extern int QueryActiveStateOrDelegate(void);
extern int Slot_EvalPackedParam(int index, int parameter);
extern void Ov002_ShowEntryLabel(u16 value21a, u16 value218,
                                u8 selectionId, int mode);

void Ov022_UpdateSelectionController(void)
{
    Ov022SelectionController *context;

    context = NNSi_FndGetCurrentRootHeap();
    if (data_0204be04 != 0) {
        return;
    }
    if (context->type != 1) {
        func_ov022_020847f0();
        return;
    }

    if (context->lastTypeOneCandidate != context->typeOneCandidate) {
        if ((context->typeOneCandidate->flags1ac & 0x204) == 0) {
            int mode = 0;

            if (Slot_EvalPackedParam(QueryActiveStateOrDelegate(), 0x53) != 0) {
                mode = 1;
            }
            Ov002_ShowEntryLabel(context->typeOneCandidate->value21a,
                                context->typeOneCandidate->value218,
                                context->typeOneCandidate->selectionId19c,
                                mode);
        } else {
            func_ov022_020847f0();
        }

        if ((context->typeOneCandidate->flags1ac & 4) == 0) {
            ((Ov022SelectionMarkOwner *)&data_0204be18[
                0x200 + context->typeOneCandidate->selectionId19c + 1])
                ->mark810 = 1;
        }
    }

    context->lastTypeOneCandidate = context->typeOneCandidate;
}

