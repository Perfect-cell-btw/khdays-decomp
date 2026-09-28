/* Updates the three number displays (three digits, value and sign). */

#include "nitro/types.h"

typedef struct {
    u16 value;
    u8 pad_0002[6];
    int rawValue;
    u8 pad_000c[4];
    int state;
    u8 pad_0014[4];
    int showSign;
    u8 pad_001c[4];
} NumberDisplay;

typedef struct {
    u8 pad_0000[0x4b10];
    NumberDisplay numberDisplays[3];
} Ov000SceneContext;

typedef struct {
    u8 pad_0000[0xc];
    int signHandleId;
    int valueHandleId;
    int digitHandleIds[3];
} NumberDisplayConfig;

extern Ov000SceneContext *data_ov000_0205ac24;
extern const NumberDisplayConfig data_ov000_0205a7ac[3];

extern int Ov000_GetDecimalDigit(int position, int value);
extern void Ov000_SetHandleActiveState(int handleId, int value);

void Ov000_UpdateNumberDisplays(void) {
    int digits[3] = {0, 0, 0};
    int i;
    NumberDisplay *display;
    int offset;

    i = 0;
    offset = i;
    do {
        display =
            (NumberDisplay *)((u8 *)data_ov000_0205ac24 + 0x4b10 + offset);

        if (display->state == 1) {
            int digit;
            int value = display->value;

            if (value > 999) {
                value = 999;
            }

            for (digit = 0; digit < 3; digit++) {
                digits[digit] = Ov000_GetDecimalDigit(digit, value);
            }

            Ov000_SetHandleActiveState(
                data_ov000_0205a7ac[i].digitHandleIds[0], digits[0]);
            Ov000_SetHandleActiveState(
                data_ov000_0205a7ac[i].digitHandleIds[1], digits[1]);
            Ov000_SetHandleActiveState(
                data_ov000_0205a7ac[i].digitHandleIds[2], digits[2]);
            Ov000_SetHandleActiveState(
                data_ov000_0205a7ac[i].valueHandleId, display->rawValue);
            Ov000_SetHandleActiveState(
                data_ov000_0205a7ac[i].signHandleId,
                -(display->showSign == 0));
        }

        i++;
        offset += sizeof(NumberDisplay);
    } while (i < 3);
}
