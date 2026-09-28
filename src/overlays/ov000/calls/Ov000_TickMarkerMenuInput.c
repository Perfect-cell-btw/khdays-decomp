/* Marker-select scene tick. Reads the pending button id: 0x20 turns the highlight on (toggle=1),
 * 0x10 turns it off; any other id resolves a confirm/back from data_0204c190 (1 -> confirm when
 * highlighted else back, 2 -> back). On confirm (action 4) it first steps the transition, then lays
 * out the four markers (selected at 0, the rest parked at -0x100000) and clears pendingMode; on
 * back (action 2) it re-enables the primary and reselects. Finally drops the highlight, notifies
 * Ov000_PushSubWidgetValue and latches nextState=action. No-ops when nothing is pending. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ov000Marker {
    int position;
    int reserved;
} Ov000Marker;

typedef struct Ov000MarkerSceneContext {
    u8 pad_0000[0x4ad0];
    int nextState;
    int transitionStep;
    u8 pad_4ad8[8];
    int pendingMode;
    u8 pad_4ae4[0x14];
    u16 pendingId;
    u8 pad_4afa[0x0e];
    int selectedMarker;
    u8 pad_4b0c[0x64];
    int toggle;
    u8 pad_4b74[0x120];
    Ov000Marker markers[4];
    u8 pad_4cb4[0xe0];
    int resetFlag;
} Ov000MarkerSceneContext;

extern Ov000MarkerSceneContext *data_ov000_0205ac24;
extern u16 data_0204c190;

extern void Ov000_PlaceCursorByMode(int enabled, int mode);
extern void PlaySound(int soundGroup, int soundId);
extern int func_02020904(void);
extern void Ov000_UpdateMenuMarkers(
    int positionEnabled, int groupEnabled, int primaryEnabled);
extern void Ov000_ArmAutoAdvanceTimer(int mode);
extern void Ov000_PushSubWidgetValue(int enabled);

void Ov000_TickMarkerMenuInput(void)
{
    int zero = 0;
    int action = zero;

    switch (data_ov000_0205ac24->pendingId) {
    case 0x20:
        if (data_ov000_0205ac24->toggle != 1) {
            data_ov000_0205ac24->toggle = 1;
            Ov000_PlaceCursorByMode(zero, data_ov000_0205ac24->toggle);
            PlaySound(zero, zero);
        }
        break;
    case 0x10:
        if (data_ov000_0205ac24->toggle != 0) {
            data_ov000_0205ac24->toggle = zero;
            Ov000_PlaceCursorByMode(zero, data_ov000_0205ac24->toggle);
            PlaySound(zero, zero);
        }
        break;
    default:
        switch (data_0204c190) {
        case 1:
            if (data_ov000_0205ac24->toggle != 0) {
                if (data_ov000_0205ac24->transitionStep != 0) {
                    func_02020904();
                }
                action = 4;
                PlaySound(zero, 1);
            } else {
                action = 2;
                PlaySound(zero, 3);
            }
            break;
        case 2:
            action = 2;
            PlaySound(zero, 3);
            break;
        default:
            break;
        }
        break;
    }

    if (action == zero) {
        return;
    }

    switch (action) {
    case 4:
        if (data_ov000_0205ac24->transitionStep == 0) {
            data_ov000_0205ac24->toggle = zero;
            Ov000_PlaceCursorByMode(zero, data_ov000_0205ac24->toggle);
            data_ov000_0205ac24->transitionStep =
                data_ov000_0205ac24->transitionStep + 1;
            data_ov000_0205ac24->resetFlag = zero;
            return;
        } else {
            int marker;

            for (marker = 0; marker < 4; marker++) {
                Ov000MarkerSceneContext *current =
                    data_ov000_0205ac24;

                if (marker == current->selectedMarker) {
                    current->markers[marker].position = zero;
                } else {
                    current->markers[marker].position = -0x100000;
                }
            }
        }

        Ov000_UpdateMenuMarkers(1, zero, zero);
        Ov000_ArmAutoAdvanceTimer(
            data_ov000_0205ac24->selectedMarker);
        data_ov000_0205ac24->pendingMode = zero;
        data_ov000_0205ac24->transitionStep = zero;
        break;
    case 2:
        data_ov000_0205ac24->transitionStep = zero;
        Ov000_UpdateMenuMarkers(zero, zero, 1);
        Ov000_PlaceCursorByMode(
            1, data_ov000_0205ac24->selectedMarker);
        break;
    default:
        break;
    }

    data_ov000_0205ac24->toggle = zero;
    Ov000_PushSubWidgetValue(zero);
    data_ov000_0205ac24->nextState = action;
    if (action != zero) {
        data_ov000_0205ac24->resetFlag = zero;
    }
}
