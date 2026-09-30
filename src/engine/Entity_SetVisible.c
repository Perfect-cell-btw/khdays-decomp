/* Dispatch veneer: indexes the 0x184-byte-stride table at gEntityMgr
 * (field at +0xc4) by `index` and tail-calls Obj_SetFlagBit3, forwarding arg2. */
extern void *Obj_SetFlagBit3();
extern int gEntityMgr;

void *Entity_SetVisible(int index, int arg2) {
    return Obj_SetFlagBit3(gEntityMgr + 0xc4 + 0x184 * index, arg2);
}
