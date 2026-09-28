typedef struct UiLayoutPos { int x,y; } UiLayoutPos;
typedef struct Ov005Context { char header[0x54]; char embeddedManager[0x4a80]; } Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern int Ov005_FindEntryById(void *,int);
extern void Ov005_ApplyOffsetSum(void *,int,const UiLayoutPos *);
void Ov005_SetEntryOffsetXY(int entryId,short x,short y) {
    UiLayoutPos offset;
    int slot;
    offset.x=x<<12;
    offset.y=y<<12;
    slot=Ov005_FindEntryById(data_ov005_0205b80c->embeddedManager,entryId);
    Ov005_ApplyOffsetSum(data_ov005_0205b80c->embeddedManager,slot,&offset);
}
