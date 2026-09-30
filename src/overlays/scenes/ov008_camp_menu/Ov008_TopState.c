/* Ov008_TopState -- title top-level state (Start dispatch), ov006. Polls the title
 * input (Ov008_PollMenuBusyState), stores it in heap[1], and on Start (1) requests scene 0x13
 * (main menu), on reset (2) requests scene 1 (logo). Returns the spawn sentinel (-2) on a
 * transition, else 0 (stay). */

#include "game/engine.h"

#include "game/scene.h"
extern int *data_ov008_02090fa8;
extern int  Ov008_PollMenuBusyState(void);
void *Ov008_TopState(void) {
    int result = 0;
    data_ov008_02090fa8[1] = Ov008_PollMenuBusyState();
    switch (data_ov008_02090fa8[1]) {
    case 0:
        break;
    case 1:
        Scene_RequestPending(SCENE_MISSION_CAMP, 0);
        result = -2;
        break;
    case 2:
        Scene_RequestPending(SCENE_TITLE, 0);
        result = -2;
        break;
    }
    return (void *)result;
}
