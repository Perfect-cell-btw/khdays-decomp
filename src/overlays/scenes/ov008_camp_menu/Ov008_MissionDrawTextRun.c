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

extern Ov006RootContext *data_ov008_02090fa4;
extern int Ov008_ResolveMissionTextColor(int color, int alternate);
extern void Text_DrawDirectional(MissionTextEngine *engine, int x, int y,
                          int color, u32 flags, int text);

void Ov008_MissionDrawTextRun(int text, int x, int y, int color,
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
        engine = &data_ov008_02090fa4->alternate.bank.engine;
    } else {
        engine = &data_ov008_02090fa4->normal.bank.engine;
    }

    foreground = Ov008_ResolveMissionTextColor(color, alternate);
    shadow = Ov008_ResolveMissionTextColor(2, alternate);
    if (draw_shadow != 0) {
        Text_DrawDirectional(engine, x + 1, y + 1, shadow, flags, text);
    }
    Text_DrawDirectional(engine, x, y, foreground, flags, text);
}
