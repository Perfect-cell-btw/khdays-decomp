/* Moves every visible layout entry horizontally by an offset from its base position (or from zero),
 * keeping its height. */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Ov008ListEntry {
    u8 pad_0000[0x84];
    u32 flags;
} Ov008ListEntry;

extern void *NNS_FndGetNextListObject(void *list, void *previous);
extern void MI_CpuFill8(void *destination, int value, int size);
extern void MI_CpuCopy8(const void *source, void *destination, int size);
extern Point *Ov025_ApplyFirstValidSlot(int owner, Ov008ListEntry *entry);
extern Point *Ov025_GetEntryBlock2c(int owner, Ov008ListEntry *entry);
extern void Ov025_ReleaseTwoSlotsEx(
    int owner, Ov008ListEntry *entry, const Point *position);

void Ov025_OffsetActiveEntryX(int owner, int xOffset, int clearBase)
{
    Point finalPosition;
    Point basePosition;
    Ov008ListEntry *entry;

    entry = NNS_FndGetNextListObject((void *)(owner + 0x4a38), 0);
    if (entry == 0) {
        return;
    }

    do {
        if (((entry->flags << 28) >> 31) == 0) {
            Point *currentPosition;

            if (clearBase != 0) {
                MI_CpuFill8(&basePosition, 0, sizeof(basePosition));
            } else {
                Point *source = Ov025_GetEntryBlock2c(owner, entry);
                MI_CpuCopy8(source, &basePosition, sizeof(basePosition));
            }

            currentPosition = Ov025_ApplyFirstValidSlot(owner, entry);
            finalPosition.x = basePosition.x + xOffset;
            finalPosition.y = currentPosition->y;
            Ov025_ReleaseTwoSlotsEx(owner, entry, &finalPosition);
        }

        entry = NNS_FndGetNextListObject(
            (void *)(owner + 0x4a38), entry);
    } while (entry != 0);
}
