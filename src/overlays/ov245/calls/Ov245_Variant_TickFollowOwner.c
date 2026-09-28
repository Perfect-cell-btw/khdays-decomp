/* Retunes the rig at +0x14 of the sub-object's block at +0x44c and then notifies, with the
 * notify flag forced to 0 while bit 1 of the halfword at +0x1ac is set. */
extern void Ov107_MoveNodeAndRelayout(char *self, void *p);
extern void Ov107_ProcessObjectTick(char *self, int flag);

void Ov245_Variant_TickFollowOwner(char *self, int flag) {
    char *sub = *(char **)(self + 0x3c8);
    if (*(unsigned short *)(sub + 0x1ac) & 2) {
        flag = 0;
    }
    Ov107_MoveNodeAndRelayout(self, *(char **)(sub + 0x44c) + 0x14);
    Ov107_ProcessObjectTick(self, flag);
}
