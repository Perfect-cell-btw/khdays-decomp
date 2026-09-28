typedef unsigned int u32;

typedef struct {
    u32 field_0;
    void *volatile instance;
} MissionControllerState;

extern MissionControllerState data_ov006_020565e4;
extern unsigned char data_ov006_020563c0;
extern void *InstantiateClass(void *class_desc, int arg);

void Ov006_MissionEnsureController(int arg) {
    if (data_ov006_020565e4.instance != 0) {
        return;
    }

    data_ov006_020565e4.instance = InstantiateClass(&data_ov006_020563c0, arg);
}
