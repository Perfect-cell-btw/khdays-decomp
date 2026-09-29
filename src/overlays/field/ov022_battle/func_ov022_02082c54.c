/* Records the local player's group, requests a save for it, runs the frame without input and moves
 * to the pause menu. */

#include "game/engine.h"

extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov022_GetEntryField66(unsigned int arg0);
extern void Ov002_Link_RequestSave(int arg0);
extern void Ov022_UpdateCameraAndViews(int arg0);
extern int data_0204be04;
extern void Ov022_StartPauseMenu(void);

int func_ov022_02082c54(void) {
    int h = NNSi_FndGetCurrentRootHeap();
    if (*(unsigned char *)&data_0204be04 != 0) return 0;
    *(char *)(h + 0x3d) = (char)Ov022_GetEntryField66(QueryActiveStateOrDelegate());
    Ov002_Link_RequestSave(*(char *)(h + 0x3d));
    Ov022_UpdateCameraAndViews(0);
    return (int)Ov022_StartPauseMenu;
}
