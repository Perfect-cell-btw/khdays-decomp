/* Walk the object's NNS list for `target` and make it current: +0x18 gets the object and +0x1c gets
 * its payload at object+8. A null target, or one not in the list, leaves the walk's last result
 * (null) current. Refreshes through EnqueueObjGfxCommand when the last argument is set. The +0x18 /
 * +0x1c pair is the same one TileSurface_Init seeds via TileSurface_AddCanvas, which is what ties
 * this module to that struct. OPEN: the list this walks sits at +0x30, past the 0x3c
 * TileSurface_Init zeroes -- so either the real object extends beyond the TileSurface header or the
 * scratch offsets in the old C file are off. Worth settling before trusting the tail of that
 * layout. */

extern void *NNS_FndGetNextListObject(void *list, void *object);
extern void EnqueueObjGfxCommand(void *p);

typedef struct {
    char _0[0x18];
    void *current;
    void *currentData;
    char _20[0xc];
    char list[0x10];
} X02030094;

void TileSurface_SetCurrentItem(X02030094 *p, void *target, int update)
{
    void *cur = NNS_FndGetNextListObject(p->list, 0);

    if (target != 0 && cur != 0) {
        for (;;) {
            if (cur == target)
                break;
            cur = NNS_FndGetNextListObject(p->list, cur);
            if (cur == 0)
                break;
        }
    }

    p->currentData = (char *)cur + 8;
    p->current = cur;

    if (update != 0)
        EnqueueObjGfxCommand(p);
}
