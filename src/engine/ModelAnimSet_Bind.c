/* ModelAnimSet_Bind -- bind a model instance's animations, MAIN. The model file holds five animation
 * groups (archive members 0..4, counted by NitroFile_GetSection0Byte9); one default-heap block holds a pointer
 * slot per animation, handed out group by group (a group without animations gets NULL; with none
 * at all the set is cleared). Every animation is then allocated as an animation object for the
 * instance's resource model (NNS_G3dAllocAnmObj with the default allocator) and initialised
 * (NNS_G3dAnmObjInit); group 3 (texture pattern) also gets the texture set of the instance's
 * resource list. The per-group counts and `texSrc` are recorded in the set. Codegen: each loop
 * keeps its own block-scoped count `n`; one function-scope `n` swaps the third loop's n/anm registers. */

#include "nitro/types.h"

typedef struct ModelResList {
    char pad00[0xc];
    void *texFile;                      /* +0x0c */
} ModelResList;

typedef struct ModelInst {
    char pad00[0x74];
    ModelResList *resList;              /* +0x74 */
    void *resMdl;                       /* +0x78 */
} ModelInst;

typedef struct ModelAnimSet {
    u16 count[5];                       /* +0x00 */
    u16 texSrc;                         /* +0x0a */
    int pad0c;
    void **objs[5];                     /* +0x10 */
} ModelAnimSet;

extern void *Archive_GetMember(void *file, int nMember, int nSub);
extern int NitroFile_GetSection0Byte9(void *anmSet);
extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern void MI_CpuFill8(void *dest, int data, unsigned int size);
extern void *NNS_G3dGetAnmByIdx(void *anmSet, int idx);                          /* NNS_G3dGetAnmByIdx */
extern void *NNSi_FndGetAllocatorForDefaultHeap(int idx);
extern void *NNS_G3dAllocAnmObj(void *allocator, void *anm, void *resMdl);       /* NNS_G3dAllocAnmObj */
extern void *NNS_G3dGetTex(void *file);                                     /* NNS_G3dGetTex */
extern void NNS_G3dAnmObjInit(void *anmObj, void *anm, void *resMdl, void *tex); /* NNS_G3dAnmObjInit */

void ModelAnimSet_Bind(ModelAnimSet *set, ModelInst *inst, void *file, int texSrc)
{
    int i;
    int total = 0;
    int j;

    for (i = 0; i < 5; i++) {
        total += NitroFile_GetSection0Byte9(Archive_GetMember(file, i, 0));
    }
    if (total > 0) {
        void **slot = NNSi_FndAllocFromDefaultExpHeap(total * 4);

        for (i = 0; i < 5; i++) {
            int n = NitroFile_GetSection0Byte9(Archive_GetMember(file, i, 0));
            if (n > 0) {
                set->objs[i] = slot;
                slot += n;
            } else {
                set->objs[i] = 0;
            }
        }
    } else {
        MI_CpuFill8(set, 0, sizeof(ModelAnimSet));
    }
    for (i = 0; i < 5; i++) {
        void *anmSet = Archive_GetMember(file, i, 0);
        int n = NitroFile_GetSection0Byte9(anmSet);

        for (j = 0; j < n; j++) {
            void *anm = NNS_G3dGetAnmByIdx(anmSet, j);

            set->objs[i][j] = NNS_G3dAllocAnmObj(NNSi_FndGetAllocatorForDefaultHeap(0), anm, inst->resMdl);
            NNS_G3dAnmObjInit(set->objs[i][j], anm, inst->resMdl,
                          i == 3 ? NNS_G3dGetTex(Archive_GetMember(inst->resList->texFile, 7, 0)) : 0);
        }
        set->count[i] = n;
    }
    set->texSrc = texSrc;
}
