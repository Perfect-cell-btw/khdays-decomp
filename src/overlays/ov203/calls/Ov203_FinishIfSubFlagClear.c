/* Marks the task finished when the owner's sub-object flag is clear; otherwise returns it. */

extern int Task_MarkFinished();

struct Sub { char pad[0xad]; unsigned char flag; };
struct Mid { char pad0[4]; struct Sub *sub; };
struct Obj { char pad0[4]; struct Mid *mid; };

int Ov203_FinishIfSubFlagClear(struct Obj *obj) {
    if (obj->mid->sub->flag == 0) {
        return Task_MarkFinished();
    }
    return (int)obj;
}
