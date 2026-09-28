/* Refreshes the child selector at +0x388, then runs the object tick. */

extern int Ov107_RefreshAndSelectChild();
extern int Ov107_ProcessObjectTick();

struct S { char pad[0x388]; int field_388; };

int Ov263_TickWithChildRefresh(struct S *a, int b) {
    Ov107_RefreshAndSelectChild(a->field_388);
    return Ov107_ProcessObjectTick(a, b);
}
