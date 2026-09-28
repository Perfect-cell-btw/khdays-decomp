/* Refreshes the child selector, runs the object tick, then copies the object's block into both
 * child nodes (+0x10). */

extern int Ov107_ProcessObjectTick();
extern int Ov107_RefreshAndSelectChild();

typedef struct {
    int a[4];
    int b[4];
    int c[3];
} Block;

typedef struct {
    char _pad0[0xa0];
    Block block;        /* 0xa0 .. 0xcc */
    char _pad1[0x388 - 0xcc];
    char **p388;        /* 0x388 */
    char *p38c;         /* 0x38c */
    int field_390;      /* 0x390 */
} Obj;

void Ov205_TickAndSyncChildren(Obj *obj, int arg1)
{
    Ov107_RefreshAndSelectChild(obj->field_390);
    Ov107_ProcessObjectTick(obj, arg1);

    *(Block *)(*obj->p388 + 0x10) = obj->block;
    *(Block *)(obj->p38c + 0x10) = obj->block;
}
