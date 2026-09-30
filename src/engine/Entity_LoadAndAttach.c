/* Create/register entity[index]: r=Archive_LoadFile(p2,1); attach via
 * ModelGroup_Open(cont,r); store r at base+index*4+0x44; return 1. */
#pragma thumb on

extern int gEntityMgr;
extern int Archive_LoadFile(int p2, int one);
extern void ModelGroup_Open(void *cont, int r);

int Entity_LoadAndAttach(int index, int p2) {
    int base = gEntityMgr;
    int r = Archive_LoadFile(p2, 1);
    void *cont = (void *)(gEntityMgr + 4 + index * 8);
    ModelGroup_Open(cont, r);
    *(int *)(base + index * 4 + 0x44) = r;
    return 1;
}
