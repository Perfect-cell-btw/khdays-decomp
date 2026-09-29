/*
 * Obj_Destroy - tear down and free an object. Enters a scoped allocator arena
 * (Heap_SetCurrent(obj[7])), publishes the object as the "currently destroying" one in the registry
 * global (data_0204c058[1]) while its destructor callback (obj[6], if any) runs, restores the
 * previous value, unlinks it from the object registry (Obj_UnlinkNode), frees its auxiliary buffer
 * (obj[8]) if present, frees the object itself through the heap wrapper (ExpHeap_Free with
 * data_0204c024[0]), leaves the arena, and returns the object's saved field obj[3].
 *
 * ARM. Matching notes: cache the destructor pointer in a local (obj[6] is loaded once for the null
 * check AND the call) and declare the saved-global local BEFORE the arena handle so mwcc keeps the
 * object in r5 and the saved value in r6 (declaring them the other way swaps the pair).
 */

extern int  Heap_SetCurrent(int arena);      /* enter/leave scoped allocator arena */
extern void Obj_UnlinkNode(int node);        /* Obj_UnlinkNode */
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void ExpHeap_Free(void *obj, void *heap);
extern int  data_0204c058[];
extern int  data_0204c024[];

int Obj_Destroy(int *param_1)
{
    int uVar3;
    void (*cb)(void);
    int iVar2;

    iVar2 = Heap_SetCurrent(param_1[7]);
    uVar3 = data_0204c058[1];
    data_0204c058[1] = (int)param_1;
    cb = (void (*)(void))param_1[6];
    if (cb != 0) {
        cb();
    }
    *param_1 = 0;
    data_0204c058[1] = uVar3;
    Obj_UnlinkNode((int)param_1);
    uVar3 = param_1[3];
    if (param_1[8] != 0) {
        NNSi_FndFreeFromDefaultHeap((void *)param_1[8]);
    }
    ExpHeap_Free(param_1, (void *)data_0204c024[0]);
    Heap_SetCurrent(iVar2);
    return uVar3;
}
