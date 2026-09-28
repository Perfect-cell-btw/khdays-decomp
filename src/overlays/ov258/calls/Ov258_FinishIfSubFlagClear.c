extern int Task_MarkFinished();

struct Sub { char pad[0xad]; unsigned char flag; };
struct Mid { char pad0[4]; struct Sub *sub; };
struct Obj { char pad0[4]; struct Mid *mid; };

int Ov258_FinishIfSubFlagClear(struct Obj *obj) {
    if (obj->mid->sub->flag == 0) {
        return Task_MarkFinished();
    }
    return (int)obj;
}
