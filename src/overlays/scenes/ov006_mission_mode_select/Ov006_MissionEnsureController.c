#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"
/* Creates the mission select controller instance when it does not exist. */

extern unsigned char data_ov006_020563c0;
extern void *InstantiateClass(void *class_desc, int arg);

void Ov006_MissionEnsureController(int arg) {
    if (data_ov006_020565e4.pController != 0) {
        return;
    }

    data_ov006_020565e4.pController = InstantiateClass(&data_ov006_020563c0, arg);
}
