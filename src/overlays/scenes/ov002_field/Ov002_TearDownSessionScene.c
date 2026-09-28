/* Scene exit for the context published at data_ov002_0207f9f4's sibling slot:
 * when the party count at +0xc is more than one, hand the object at +0x10 back
 * through slot 0xc, run the two teardown steps and finally drop the global.
 * Session_GetLocalPlayerIndex is called for its side effect only -- the ROM discards r0. */
extern int Session_GetLocalPlayerIndex(void);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_3(int handle, int slot);
extern void Ov002_ClearSessionField14(void);
extern void Ov002_ForwardToSubDc_6(int a);

extern int data_ov002_0207f9f0;

void Ov002_TearDownSessionScene(void) {
    int ctx = data_ov002_0207f9f0;

    Session_GetLocalPlayerIndex();
    if (*(int *)(ctx + 0xc) >= 2) {
        Ov002_Ctx_SetTagTrackerNodeArmed_3(*(int *)(ctx + 0x10), 0xc);
    }
    Ov002_ClearSessionField14();
    Ov002_ForwardToSubDc_6(0);
    data_ov002_0207f9f0 = 0;
}
