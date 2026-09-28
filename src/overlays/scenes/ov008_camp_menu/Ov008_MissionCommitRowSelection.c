/* Commits the selected mission row when it is complete and ready: with the session alive, switches
 * to the select state, makes the row the active record and clears the input and work buffers;
 * otherwise goes idle and drives the sound; returns whether it committed. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 field_00[0xf];
    u16 item_count;
    u16 field_3e;
    u16 ready;
    u16 field_42;
    u32 field_44[0x1f];
} MissionRecord;

typedef struct {
    void *buffer;
    u32 field_4;
} MissionWorkBuffer;

typedef struct {
    void *primary_buffer;
    u8 pad_004[4];
    MissionWorkBuffer work_buffers[4];
    u8 pad_028[8];
    u32 work_states[4];
    MissionRecord active_record;
    volatile u8 row_count;
    u8 pad_101[3];
    MissionRecord rows[4];
    u32 row_states[4];
    u8 selection_block[0x18];
    u8 input_state[0x68];
} MissionContext;

typedef struct {
    MissionContext *context;
    void *controller_instance;
} MissionGlobals;

extern MissionGlobals data_ov008_02090f24;
extern int Game_PollSceneAlive(void);
extern void Obj_SetField14(void *instance, void (*callback)(void));
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov008_MissionDriveSound(void);
extern void Ov008_MissionSelectStateCallback(void);
extern void Ov008_MissionSceneIdleCallback(void);

int Ov008_MissionCommitRowSelection(int index) {
    int result = 0;
    MissionRecord *record = &data_ov008_02090f24.context->rows[index];

    if (record->item_count >= 16 && record->ready == 1) {
        if (Game_PollSceneAlive() == 1) {
            u8 i;

            Obj_SetField14(data_ov008_02090f24.controller_instance,
                          Ov008_MissionSelectStateCallback);
            data_ov008_02090f24.context->active_record =
                data_ov008_02090f24.context->rows[index];
            MI_CpuFill8(data_ov008_02090f24.context->input_state, 0,
                        sizeof(data_ov008_02090f24.context->input_state));
            MI_CpuFill8(data_ov008_02090f24.context->primary_buffer, 0, 0x100);

            for (i = 0; i < 4; i++) {
                MI_CpuFill8(data_ov008_02090f24.context->work_buffers[i].buffer,
                            0, 0x100);
                data_ov008_02090f24.context->work_states[i] = 0;
            }
            result = 1;
        } else {
            Obj_SetField14(data_ov008_02090f24.controller_instance,
                          Ov008_MissionSceneIdleCallback);
            Ov008_MissionDriveSound();
        }
    }

    return result;
}
