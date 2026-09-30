/* Links entity slot b under entity slot a. */

extern void LinkChildNode(int, int, int);
extern int gEntityMgr;

void EntityMgr_LinkChild(int param_1, int param_2, int param_3) {
    int base = gEntityMgr + 0xc4;
    LinkChildNode(base + param_1 * 0x184, base + param_2 * 0x184, param_3);
}
