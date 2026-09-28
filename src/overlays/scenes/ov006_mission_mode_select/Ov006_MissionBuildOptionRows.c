/* Builds the mission mode option rows for the current progress (unlocked modes by level), and
 * handles leaving the menu. */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    u8 flag_2;
    u8 flag_3;
    s8 icon;
    s8 sprite;
    u8 field_6;
    u8 pad_7;
} MissionMenuRow;

typedef struct {
    u8 pad_00[0x28];
    int single_row_mode;
    u8 pad_2c[4];
    u8 option_mask;
    u8 pad_31;
    u16 message_id;
    u16 field_34;
    u8 pad_36[0x0a];
    MissionMenuRow rows[4];
    u8 pad_60[0x0d];
    u8 parameters_ready;
} MissionMenuContext;

typedef struct {
    u8 pad_0000[0x9d8];
    u8 feature_a;
    u8 feature_b;
} MissionSystemContext;

extern MissionMenuContext *data_ov006_02056660;
extern MissionSystemContext *data_0204be18;

extern int Ov006_CanConfirmMissionMenu(void);
extern void Ov006_BlankScreensAndTeardownText(void);
extern int Ov006_GetMissionMenuSelection(void);
extern int Ov006_SetMissionCursorSelection(int selection);
extern int Ov006_Link_Poll(void);
extern int Ov006_MissionScene_GetState(void);
extern int GameState_GetField(int id, int field);
extern void Ov006_MissionScene_SetByte9520(int mask);
extern void Ov006_GetMissionRowInfo(int row, MissionMenuRow *out);
extern int Ov006_CountPlayers(void);
extern int Ov006_SetTitleMode(unsigned mode);
extern void Ov006_ResetTextLayers(void);
extern void Ov006_FlushTextLayers(void);
extern int Session_GetLocalPlayerIndex(void);
extern void Ov006_MissionScene_SetHalf95C2(int row);
extern int Ov006_RequestMenuState(unsigned state, int arg1, int arg2);
extern int Ov006_MissionSetModelPose(int pose);
extern void Ov006_MissionInitVideoScene(void);
extern void Ov006_UpdateMissionMemberMenuScreen(void);

int Ov006_MissionBuildOptionRows(void) {
    int input;
    int result = 0;
    u8 option_mask = result;
    u8 level;

    if (Ov006_CanConfirmMissionMenu() != 0) {
        Ov006_BlankScreensAndTeardownText();
        data_ov006_02056660->parameters_ready = 0;
        return (int)Ov006_MissionInitVideoScene;
    }

    Ov006_SetMissionCursorSelection(Ov006_GetMissionMenuSelection());
    if (Ov006_Link_Poll() != 2) {
        goto return_result;
    }
    if (Ov006_MissionScene_GetState() != 14) {
        return result;
    }

    GameState_GetField(0, 9);
    level = GameState_GetField(0x44e, 3);
    if (level >= 2) {
        option_mask |= 1;
    }
    if (level >= 3) {
        option_mask |= 8;
    }
    if (level >= 4) {
        option_mask |= 0x10;
    }
    if (level >= 5) {
        option_mask |= 0x20;
    }
    if (data_0204be18->feature_a != 0) {
        option_mask |= 4;
    }
    if (data_0204be18->feature_b != 0) {
        option_mask |= 2;
    }

    data_ov006_02056660->option_mask = option_mask;
    Ov006_MissionScene_SetByte9520(option_mask);

    if (data_ov006_02056660->single_row_mode != 0) {
        Ov006_GetMissionRowInfo(0, &data_ov006_02056660->rows[0]);
    } else {
        u8 i;

        input = Ov006_CountPlayers();
        for (i = 0; i < 4; i++) {
            Ov006_GetMissionRowInfo(i, &data_ov006_02056660->rows[i]);
        }
    }

    Ov006_SetTitleMode(input);
    Ov006_ResetTextLayers();
    Ov006_FlushTextLayers();
    Ov006_MissionScene_SetHalf95C2(Session_GetLocalPlayerIndex());
    Ov006_RequestMenuState(4, 1, 1);
    Ov006_MissionSetModelPose(
        data_ov006_02056660->rows[Session_GetLocalPlayerIndex()].icon);

    data_ov006_02056660->message_id = 0x35;
    data_ov006_02056660->field_34 = 0;
    result = (int)Ov006_UpdateMissionMemberMenuScreen;

return_result:
    return result;
}
