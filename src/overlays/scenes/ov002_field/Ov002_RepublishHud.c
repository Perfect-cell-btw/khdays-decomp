extern void Ov002_Panel_SelectGroup(int a);
extern void Ov002_HandlePanelInput(int a, int b);
extern void Ov002_Panel_MoveCursor(int a);
extern void Ov002_PanelSetSecondaryFlag(int a);
extern unsigned char gPartyState;
extern unsigned char data_0204c4f2;
extern unsigned char data_0204c4f3;
extern int data_0204c4fc;

/* Republishes the HUD from the saved state: the party layout, the current member, the camera
 * mode, and -- unless the member is 9 -- the active mission block. */
void Ov002_RepublishHud(void) {
    Ov002_Panel_SelectGroup(data_0204c4f2);
    Ov002_HandlePanelInput(gPartyState, -1);
    Ov002_Panel_MoveCursor(data_0204c4f3);
    if (gPartyState == 9) {
        return;
    }
    Ov002_PanelSetSecondaryFlag(data_0204c4fc);
}
