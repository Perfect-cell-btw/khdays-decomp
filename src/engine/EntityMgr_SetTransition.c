/* Sets the transition of entity slot index. */

extern void Obj_SetTransition(int, int, int);
extern int gEntityMgr;

void EntityMgr_SetTransition(int param_1, int param_2, int param_3) {
    Obj_SetTransition(gEntityMgr + 0xc4 + param_1 * 0x184, param_2, param_3);
}
