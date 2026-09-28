/* Snapshot the paused object into a 0x100-byte stack buffer and hand it to the
 * report builder. Does nothing when nothing is paused.
 *
 * The object being snapshotted is the CALLER'S, passed straight through -- r0 is
 * never written before the call. The paused-object slot is only the gate. */
extern void Utf8_ToUcs2(int object, void *out);
extern void Ov002_ShowNoticeText(void *snapshot);

typedef struct {
    char pad0000[0x8c94];
    int nPauseObject;       /* +0x8c94, -1 = none */
} Ov002RootContext;

extern Ov002RootContext *data_ov002_0207fa00;

void Ov002_SnapshotPausedObject(int object) {
    char snapshot[0x100];

    if (data_ov002_0207fa00->nPauseObject == -1) {
        return;
    }

    Utf8_ToUcs2(object, snapshot);
    Ov002_ShowNoticeText(snapshot);
}
