/* Move the selection cursor up one row, wrapping past the top to row 27, and scroll the ten-row
 * window to keep it visible: after a wrap the window top jumps to cursor - 9, and in the ordinary
 * case it simply follows the cursor down. Either adjustment clears the 'settled' flag at +0x60.
 * Ends with the move sound and a redraw. This corroborates nSelection at +2 -- it is the cursor,
 * and +0 is its window top. The window is ten rows because the wrap test is `top + 10 <= cursor`,
 * and the list is 28 rows because the wrap target is 27, which agrees with the existing rows[28].
 */

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
