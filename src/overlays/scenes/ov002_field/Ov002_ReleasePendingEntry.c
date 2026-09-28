/* Release the panel's pending entry: clear the handle's +4 and +0 around the
 * teardown. Does nothing when no context is installed -- but the handle is
 * fetched BEFORE the guard, which is why Ov002_Field_GetBlock194 runs either way. */
extern int Ov002_Field_GetBlock194(void);
extern void Ov002_FlushPendingDraw(void);

extern int data_ov002_0207f634;

void Ov002_ReleasePendingEntry(void) {
    int ctx = data_ov002_0207f634;
    int *handle = (int *)Ov002_Field_GetBlock194();

    if (ctx == 0) {
        return;
    }

    handle[1] = 0;
    Ov002_FlushPendingDraw();
    handle[0] = 0;
}
