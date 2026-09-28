/* Repaint the ten visible rows of the menu list: each row is drawn with the highlight sprite when
 * its index equals selectedRow - firstRow, otherwise with the normal sprite. Rows step 2 units
 * apart starting at y = 2. */

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Ov000_Elem_SetPos(void *spriteContext, int sprite, int x, int y);
extern void Ov000_TagTracker_InvokeCallback(void *spriteContext, int sprite);

typedef struct {
    short firstRow;
    short selectedRow;
    char pad04[0x108];
    char spriteContext[0xd034];
    int normalRowSprite;
    int selectedRowSprite;
} Ov000MenuContext;

void Ov000_RedrawVisibleMenuRows(void)
{
    Ov000MenuContext *context = (Ov000MenuContext *)NNSi_FndGetCurrentRootHeap();
    int i;
    int selected;
    short y;

    y = 2;
    i = 0;
    selected = context->selectedRow - context->firstRow;

    for (; i < 10; i++) {
        int sprite;
        if (selected == i) {
            sprite = context->selectedRowSprite;
        } else {
            sprite = context->normalRowSprite;
        }
        Ov000_Elem_SetPos(context->spriteContext, sprite, 2, y);
        Ov000_TagTracker_InvokeCallback(context->spriteContext, sprite);
        y += 2;
    }
}
