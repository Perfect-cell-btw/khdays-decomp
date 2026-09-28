typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    s16 limit;
    s16 cursor;
    u8 pad_04[0x5c];
    int changed;
} OverlaySelection;

extern void PlaySound(int x, int y);
extern void Ov000_QueueResourceTransfers(void);

void Ov000_MoveSelectionUp(OverlaySelection *selection) {
    selection->cursor--;
    if (selection->cursor < 0) {
        selection->cursor = 27;
        if (selection->limit + 10 <= selection->cursor) {
            selection->limit = selection->cursor - 9;
            selection->changed = 0;
        }
    }

    if (selection->cursor < selection->limit) {
        selection->limit = selection->cursor;
        selection->changed = 0;
    }

    PlaySound(0, 0);
    Ov000_QueueResourceTransfers();
}
