typedef void (*Ov004StateHandler)(void);

typedef struct Ov004StateHandlerTable {
    Ov004StateHandler handlers[5];
} Ov004StateHandlerTable;

extern const Ov004StateHandlerTable data_ov004_020510b8;
extern char *data_ov004_02051384;

extern void Ov004_StepLogoScale(void);
extern void Ov004_PrepareTransitionLabel(void);
extern void Ov004_StepLogoSlide(void);
extern void Ov004_StepFadeIn(void);
extern void Ov004_SubmitObjectSprites(void);
extern void Ov004_DrawRollingDigits(void);

int Ov004_StepSceneFrame(void) {
    Ov004StateHandlerTable table;
    int state;

    table = data_ov004_020510b8;
    table.handlers[*(int *)(data_ov004_02051384 + 0xaf8)]();
    Ov004_StepLogoScale();

    state = *(int *)(data_ov004_02051384 + 0xaf8);
    switch (state) {
    case 1:
        if (*(int *)(data_ov004_02051384 + 0x5584) == 0) {
            break;
        }
    case 2:
    case 3:
        Ov004_PrepareTransitionLabel();
        Ov004_StepLogoSlide();
        Ov004_StepFadeIn();
        break;
    }

    Ov004_SubmitObjectSprites();
    Ov004_DrawRollingDigits();
    return 0;
}

