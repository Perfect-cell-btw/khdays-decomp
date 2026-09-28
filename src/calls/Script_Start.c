#pragma thumb on
/* Script_Start -- start a loaded script, MAIN. The staging buffer (+0x594) holds either a bare
 * script or a "PKAC" archive: an archive is fixed up (Obj_RelocateSections, without the section-7 dispatch) and member 1 is taken, by name
 * when `name` is given (Archive_FindNameIndex) else index 0. The script's base (+0xc), code start
 * (+0x10/+0x14: past the size word) and end (+0x18) are recorded, the run state (+0x1c..+0x4b) and
 * the error slots (+0x124, +0x584..+0x58c) are cleared, and the execution context `vm` is reset:
 * stack depth 0x10, four empty call slots and counters, no current record (-1), and its four
 * 0x104-byte records initialised (Camera_Init) with the first two marked unused. Returns TRUE. */
typedef struct VmSlot {
    int a;
    int b;
    int c;
} VmSlot;

typedef struct VmRecord {
    char body[0xf8];
    int id;                             /* +0xf8 */
    char tail[0x104 - 0xfc];
} VmRecord;

typedef struct VmCtx {
    char pad000[0x2c];
    int depth;                          /* +0x02c */
    VmRecord recA[2];                   /* +0x030 */
    VmRecord recB[2];                   /* +0x238 */
    int pad440;
    VmSlot slot[4];                     /* +0x444 */
    int counter[4];                     /* +0x474 */
    int current;                        /* +0x484 */
    int pending;                        /* +0x488 */
} VmCtx;

typedef struct VmState {
    char pad00[0x20];
    int regs[10];                       /* +0x24 of the owner */
} VmState;

extern void Obj_RelocateSections(void *archive, int bDispatchSection7);   /* Obj_RelocateSections */
extern int Archive_FindNameIndex(void *archive, const char *name);   /* Archive_FindNameIndex */
extern char *Archive_GetMember(void *archive, int group, int index);   /* Archive_GetMember */
extern void MI_CpuFill8(void *dest, int data, unsigned int size);
extern void Camera_Init(VmRecord *rec);

#define ARCHIVE_MAGIC 0x504b4143   /* "CAKP" */

int Script_Start(char *o, const char *name, VmCtx *vm)
{
    int k;
    char *member;
    int index;
    int i;
    char *buf;

    buf = o + 0x594;
    *(int *)(o + 0x124) = 0;
    *(int *)(o + 0x584) = 0;
    *(int *)(o + 0x588) = 0;
    *(int *)(o + 0x58c) = 0;
    if (*(int *)buf == ARCHIVE_MAGIC) {
        Obj_RelocateSections(buf, 0);
        if (name != 0) {
            index = Archive_FindNameIndex(buf, name);
        } else {
            index = 0;
        }
        member = Archive_GetMember(buf, 1, index);
        *(char **)(o + 0xc) = member;
        *(char **)(o + 0x10) = member + 4;
        *(char **)(o + 0x14) = member + 4;
        *(char **)(o + 0x18) = *(char **)(o + 0xc) + **(int **)(o + 0xc);
    } else {
        *(char **)(o + 0xc) = buf;
        *(char **)(o + 0x10) = buf + 4;
        *(char **)(o + 0x14) = buf + 4;
        *(char **)(o + 0x18) = buf + **(int **)(o + 0xc);
    }
    *(int *)(o + 0x1c) = 0;
    *(int *)(o + 0x20) = 0;
    MI_CpuFill8(((VmState *)(o + 4))->regs, 0, sizeof(((VmState *)0)->regs));
    vm->depth = 0x10;
    for (i = 0; i < 4; i++) {
        vm->slot[i].a = vm->slot[i].b = vm->slot[i].c = 0;
        vm->counter[i] = 0;
    }
    vm->current = -1;
    vm->pending = 0;
    *(VmCtx **)(o + 0x128) = vm;
    for (k = 0; k < 2; k++) {
        Camera_Init(&(*(VmCtx **)(o + 0x128))->recA[k]);
        (*(VmCtx **)(o + 0x128))->recA[k].id = -1;
        Camera_Init(&(*(VmCtx **)(o + 0x128))->recB[k]);
    }
    return 1;
}
