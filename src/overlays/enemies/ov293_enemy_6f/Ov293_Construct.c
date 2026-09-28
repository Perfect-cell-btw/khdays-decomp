/* Constructor of the ov293 enemy: installs the handlers (+8 tick, +0xc draw, +0x1c message,
 * +0x30/+0x34 hit callbacks, +0x1d0 on-hit, +0x1dc finish), seeds the +0x64 pose (scale 0x800,
 * y 0x800), builds the primary item from pool entry 0 (subscribed), resolves three named joints
 * into +0x390/+0x394/+0x398 (the first's +0x14 block kept at +0x2cc), keeps the named motion
 * handle (+0x39c), the two sub-items of the overlay's kind pair in a fresh 16-byte slot table
 * (+0x3a0, attached, bit 1 on their +0x5c), configures actions 0/1/2/4 (rate 0x1800) and
 * creates two placements from the zero pose at scale 0x800: +0x388 on the +0x22c list and
 * +0x38c on the +0x144 list; sound 0x11a is loaded. */
struct v2 { int w[2]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v2 data_ov293_020d35fc;
extern struct v3 data_02041dc8;
extern unsigned short data_ov293_020d362c[];
extern unsigned short data_ov293_020d3634[];
extern unsigned short data_ov293_020d3644[];
extern int data_ov293_020d3654;
extern void Ov293_ReleaseSubObjectsAndListThenNotify(void), Ov293_TickWithChildRefresh(void), Ov293_HandleMessage(void);
extern void Ov293_CopyBlockToTwoNodesThenNotify(void), Ov293_CreateRegistryEntryAndLink(void), Ov293_OnHit(void);
extern void Ov293_ForwardAnimEvent(void);
extern void *Ov107_PackTextureHandle();
extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern char *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void *CallocInstance();
extern void Ov107_EnqueueValue();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern int Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov293_Construct(int param_1)
{
    struct v2 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    int r;

    tbl = data_ov293_020d35fc;
    *(void **)(param_1 + 8) = Ov293_ReleaseSubObjectsAndListThenNotify;
    *(void **)(param_1 + 0xc) = Ov293_TickWithChildRefresh;
    *(void **)(param_1 + 0x1c) = Ov293_HandleMessage;
    *(void **)(param_1 + 0x34) = Ov293_CopyBlockToTwoNodesThenNotify;
    *(void **)(param_1 + 0x30) = Ov293_CreateRegistryEntryAndLink;
    *(void **)(param_1 + 0x1d0) = Ov293_OnHit;
    *(void **)(param_1 + 0x1dc) = Ov293_ForwardAnimEvent;
    *(int *)(param_1 + 0x70) = 0x800;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x800;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(char **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov293_020d362c);
    *(char **)(param_1 + 0x394) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov293_020d3634);
    *(char **)(param_1 + 0x398) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov293_020d3644);
    *(char **)(param_1 + 0x2cc) = *(char **)(param_1 + 0x390) + 0x14;
    *(void **)(param_1 + 0x39c) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &data_ov293_020d3654);
    *(void **)(param_1 + 0x3a0) = CallocInstance(0x10);
    for (i = 0; i < 2; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3a0))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, tbl.w[i]));
        Ov107_EnqueueValue(param_1, ((struct slot *)*(int *)(param_1 + 0x3a0))[i].ptr);
        *(int *)((char *)((struct slot *)*(int *)(param_1 + 0x3a0))[i].ptr + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x1800);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x1800);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x1800);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x1800);
    g.t = data_02041dc8;
    g.scale = 0x800;
    *(void **)(param_1 + 0x388) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x388) = Ov107_CloneResourceTransform(&g);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        r = Ov107_CloneResourceTransform(&g);
        *p = r;
        *(int *)(param_1 + 0x38c) = r;
    }
    Res_RequestIdPair(0x11a);
}
