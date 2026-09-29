/* Collects lock-on candidates for an actor: scores them by facing or distance (by ability), then
 * scans the candidate container's list; returns whether one was selected. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov022LowByte16 {
    unsigned short lowByte : 8;
    unsigned short highByte : 8;
} Ov022LowByte16;

typedef struct Ov022Candidate {
    char pad_0000[0x60];
    Ov022LowByte16 flags60;
    char pad_0062[0x117];
    u8 special179;
    char pad_017a[0x32];
    u16 flags1ac;
    char pad_01ae[0x6a];
    s16 field218;
    char pad_021a[0x12];
    char list22c[4];
} Ov022Candidate;

typedef struct Ov022IteratorNode {
    Ov022Candidate *item;
} Ov022IteratorNode;

typedef struct Ov022CandidateContainer {
    char pad_0000[0x80];
    char list80[4];
} Ov022CandidateContainer;

typedef struct Ov022ActorSelectionLink {
    char pad_0000[4];
    Ov022CandidateContainer *container4;
} Ov022ActorSelectionLink;

typedef struct Ov022Actor {
    char pad_0000[9];
    u8 index9;
    char pad_000a[0x4e2];
    Ov022ActorSelectionLink *selection4ec;
} Ov022Actor;

extern u8 data_0204c248[];
extern u8 data_0204c240;

extern void *func_ov022_020881f8(int index);
extern int Ov022_ScoreCandidateByFacing(u32 *selectionFlags, int index,
                               int bestDistance);
extern int Ov022_ScoreCandidateByDistance(u32 *selectionFlags, int index,
                               int bestDistance);
extern Ov022IteratorNode *List_First(void *list);
extern int Ov022_ScoreCandidatePart(u32 *selectionFlags, int index,
                               Ov022Candidate *candidate, int bestDistance);

int Ov022_CollectActorCandidates(u32 *selectionFlags, int index)
{
    Ov022CandidateContainer *container;
    Ov022Actor *actor;
    int result = 0;
    int ready = 1;
    int bestDistance;
    Ov022IteratorNode *iterator;
    Ov022Candidate *candidate;

    func_ov022_020881f8(index);
    actor = GetEntryField20ByIndex(index);
    bestDistance = 0x9000;
    if (Slot_EvalPackedParam(actor->index9, 0x55) != 0) {
        bestDistance = 0xd800;
    }

    {
        int scannedDistance =
            Ov022_ScoreCandidateByFacing(selectionFlags, index, bestDistance);
        if (scannedDistance != bestDistance) {
            result = 1;
        }
    }

    if (data_0204c248[0x0b] != 0 && (data_0204c240 & 4) != 0) {
        {
            int scannedDistance =
                Ov022_ScoreCandidateByDistance(selectionFlags, index, bestDistance);
            if (scannedDistance != bestDistance) {
                result = 1;
            }
        }
    }

    if (actor->selection4ec == 0) {
        ready = 0;
    } else {
        container = actor->selection4ec->container4;
        if (container == 0) {
            ready = 0;
        }
    }

    if (ready != 0) {
        iterator = List_First(container->list80);
        candidate = iterator == 0 ? 0 : iterator->item;
        while (candidate != 0) {
            if ((candidate->flags1ac & 2) == 0 &&
                (candidate->flags60.lowByte & 1) != 0 &&
                (candidate->flags1ac & 1) == 0 &&
                candidate->field218 != 0) {
                if (Ov022_ScoreCandidatePart(selectionFlags, index, candidate,
                                         bestDistance) != 0) {
                    result = 1;
                }
            }

            iterator = List_Next(container->list80);
            candidate = iterator == 0 ? 0 : iterator->item;
        }
    }

    return result;
}

