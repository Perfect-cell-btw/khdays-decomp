/* Ov006_TopState -- Mission Mode top-level state (Start dispatch), ov006. Polls the Mission Mode
 * input (Ov006_PollInput), stores it in heap[1], and on Start (1) requests scene 0x13
 * (main menu), on reset (2) requests scene 1 (logo). Returns the spawn sentinel (-2) on a
 * transition, else 0 (stay). */

#include "game/engine.h"

extern int *data_ov006_02056668;
extern int  Ov006_PollInput(void);
void *Ov006_TopState(void) {
    int result = 0;
    data_ov006_02056668[1] = Ov006_PollInput();
    switch (data_ov006_02056668[1]) {
    case 0:
        break;
    case 1:
        Scene_RequestPending(0x13, 0);
        result = -2;
        break;
    case 2:
        Scene_RequestPending(1, 0);
        result = -2;
        break;
    }
    return (void *)result;
}
