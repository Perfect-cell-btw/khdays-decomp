/* Place a result tile by tag and dispatch the tracker's drawing callback. */
typedef struct Ov000TileBlitRequest Ov000TileBlitRequest;
typedef struct Ov000ResourceTracker { char data[76]; } Ov000ResourceTracker;
typedef struct Ov005ResultContext { char unknown00[8]; Ov000ResourceTracker resourceTracker; } Ov005ResultContext;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov000TileBlitRequest *Ov005_FindEntryByTag(Ov000ResourceTracker *, int);
extern void Ov005_Elem_SetPos(Ov000ResourceTracker *, Ov000TileBlitRequest *, int, int);
extern void Ov005_TagTracker_InvokeCallback(Ov000ResourceTracker *, Ov000TileBlitRequest *);
void Ov005_DrawResultTile(int tileId, int column, int row) {
    Ov005ResultContext *context = data_ov005_0205b810;
    Ov000TileBlitRequest *entry = Ov005_FindEntryByTag(&context->resourceTracker, (unsigned short)tileId);
    Ov005_Elem_SetPos(&context->resourceTracker, entry, column, row);
    Ov005_TagTracker_InvokeCallback(&context->resourceTracker, entry);
}
