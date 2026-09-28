/* Draws a text run for the mission menu with the style's glyph flags, in the normal or alternate
 * text bank, with an optional one-pixel shadow. */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 bytes[1];
} MissionTextEngine;

typedef struct {
    u8 pad_0000[0x9400];
    MissionTextEngine engine;
} MissionTextBank;

typedef struct {
    u8 pad_000[0x36c];
    MissionTextBank bank;
} MissionAlternateTextLayout;

typedef struct {
    u8 pad_000[0x3b8];
    MissionTextBank bank;
} MissionDefaultTextLayout;

typedef union {
    MissionAlternateTextLayout alternate;
    MissionDefaultTextLayout normal;
} Ov006RootContext;

extern Ov006RootContext *data_ov006_02056664;
extern int Ov006_ResolveMissionTextColor(int color, int alternate);
extern void Text_DrawDirectional(MissionTextEngine *engine, int x, int y,
                          int color, u32 flags, int text);

void Ov006_MissionDrawTextRun(int text, int x, int y, int color,
                         int draw_shadow, int style, int alternate) {
    u32 flags = 0x200;
    MissionTextEngine *engine;
    int foreground;
    int shadow;

    switch (style) {
    case 1:
        flags = 0x821;
        break;
    case 2:
        flags = 0x411;
        break;
    case 3:
        flags = 0x412;
        break;
    }

    if (alternate != 0) {
        engine = &data_ov006_02056664->alternate.bank.engine;
    } else {
        engine = &data_ov006_02056664->normal.bank.engine;
    }

    foreground = Ov006_ResolveMissionTextColor(color, alternate);
    shadow = Ov006_ResolveMissionTextColor(2, alternate);
    if (draw_shadow != 0) {
        Text_DrawDirectional(engine, x + 1, y + 1, shadow, flags, text);
    }
    Text_DrawDirectional(engine, x, y, foreground, flags, text);
}
