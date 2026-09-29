/* Draws the visible reward item icons of both columns and their new-item indicators. */

#include "nitro/types.h"

typedef struct Ov005MenuQuad Ov005MenuQuad;
typedef struct Ov005ListWindow {char opaque[2];signed char firstVisible;} Ov005ListWindow;
typedef struct Ov005MenuItem {char opaque[0x244];int indicatorState;} Ov005MenuItem;
extern char *data_ov005_0205b80c;
extern signed char Ov005_GetVisibleItemCount(int row);
extern void Ov005_SetupMenuCamera(void);
extern void Ov005_DrawMenuQuad(Ov005MenuQuad *quad);
extern void Ov005_DrawMenuHookNoOp(void);
extern void Slot_SetVisible(void *manager,int slot,int visible);
extern void Slot_ForwardToEntry(void *manager,int slot,unsigned int frame);
#define MANAGER (*(void **)(data_ov005_0205b80c+0x4ad4))
#define SLOT(row,index) (*(int *)((char *)((row)*0x1c)+(int)data_ov005_0205b80c+(index)*4+0x62140))
void Ov005_DrawVisibleMenuItems(void) {
    u8 i;
    Ov005ListWindow *window=(Ov005ListWindow *)(data_ov005_0205b80c+0x4bfc);
    u8 row;
    Ov005_SetupMenuCamera();
    for (row=0;row<2;row++) {
        signed char count=Ov005_GetVisibleItemCount(row);
        for (i=0;i<count;i++) {
            Ov005_DrawMenuQuad((Ov005MenuQuad *)(data_ov005_0205b80c+0x61f48+row*0xfc+i*0x24));
            switch ((*(Ov005MenuItem **)((char *)(row*0x9f0)+(int)data_ov005_0205b80c+(window->firstVisible+i)*4+0x60168))->indicatorState) {
            case 0:Slot_SetVisible(MANAGER,SLOT(row,i),0);break;
            case 1:Slot_SetVisible(MANAGER,SLOT(row,i),1);Slot_ForwardToEntry(MANAGER,SLOT(row,i),0);break;
            case 2:Slot_SetVisible(MANAGER,SLOT(row,i),1);Slot_ForwardToEntry(MANAGER,SLOT(row,i),1);break;
            }
        }
        for (;i<7;i++) Slot_SetVisible(MANAGER,SLOT(row,i),0);
    }
    Ov005_DrawMenuHookNoOp();
}
