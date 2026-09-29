/* Releases the field resources: detaches and frees the actor node and unloads the actor overlay
 * when one is loaded, frees the two buffers and resets the entry table. */

#include "game/engine.h"

typedef struct {
    char pad00[0x18];
    int nodeId;     /* +0x18, -1 when none */
    char pad1c[0x28];
    void *bufA;     /* +0x44 */
    char pad48[4];
    void *bufB;     /* +0x4c */
} Ov002Res;

typedef struct {
    char pad00[0x74];
    int f74;
    int f78;
} Ov107Node;

extern Ov107Node *Ov107_GetActorManager(void);
extern void Ov107_VeneerTo_Obj_Destroy(int nodeId);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void Ov002_ResetEntryTable(void);

extern Ov002Res *data_ov002_0207fa14;

void Ov002_ReleaseResources(void) {
    Ov002Res *r = data_ov002_0207fa14;

    if (r->nodeId != -1) {
        Ov107_GetActorManager()->f74 = 0;
        Ov107_GetActorManager()->f78 = 0;
        Ov107_VeneerTo_Obj_Destroy(r->nodeId);
        UnloadActorOverlay();
        r->nodeId = -1;
    }
    if (r->bufA != 0) {
        NNSi_FndFreeFromDefaultHeap(r->bufA);
        r->bufA = 0;
    }
    if (r->bufB != 0) {
        NNSi_FndFreeFromDefaultHeap(r->bufB);
        r->bufB = 0;
    }
    Ov002_ResetEntryTable();
}
