typedef unsigned char u8;

typedef union Ov008FlagsByte {
    u8 raw;
    struct {
        u8 bit0 : 1;
        u8 synchronized : 1;
        u8 rest : 6;
    } bits;
} Ov008FlagsByte;

typedef struct Ov008MenuContext {
    u8 pad_0000[0x48];
    Ov008FlagsByte sharedFlags;
} Ov008MenuContext;

extern Ov008MenuContext *data_ov008_02090f00;

extern void Ov008_UpdateMenuInput(void);
extern int Ov008_CommitPage(int mode);
extern int Ov008_GetCtxField9678(void);
extern int Ov008_TeardownMenu2D(void);
extern int GameState_IsFlagSet(int flagId);
extern void GameSession_SetSyncEnabled(int enabled);

extern void Ov008_OpenShopState(void);
extern void Ov008_EnterSubMenu(void);
extern void Ov008_EnsureLeftSubMenu(void);
extern void Ov008_RefreshAndPickScene(void);
extern void Ov008_CommitSelectedPage(void);
extern void Ov008_WaitForLocalFlagSyncState(void);

void *Ov008_RouteCommittedPageState(void)
{
    void *result = 0;

    Ov008_UpdateMenuInput();
    if (Ov008_CommitPage(0) != 0) {
        switch (Ov008_GetCtxField9678()) {
        case 3:
            result = (void *)Ov008_OpenShopState;
            Ov008_TeardownMenu2D();
            break;
        case 4:
            Ov008_TeardownMenu2D();
            result = (void *)Ov008_EnterSubMenu;
            break;
        case 7:
            result = (void *)Ov008_EnsureLeftSubMenu;
            break;
        case 8:
            result = (void *)Ov008_RefreshAndPickScene;
            break;
        default:
        {
            u8 synchronized =
                data_ov008_02090f00->sharedFlags.bits.synchronized;
            int flagSet = GameState_IsFlagSet(0x2010) != 0;

            if (synchronized == flagSet) {
                result = (void *)Ov008_CommitSelectedPage;
            } else {
                data_ov008_02090f00->sharedFlags.bits.synchronized =
                    (u8)flagSet;
                GameSession_SetSyncEnabled(1);
                result = (void *)Ov008_WaitForLocalFlagSyncState;
            }
            Ov008_TeardownMenu2D();
            break;
        }
        }
    }
    return result;
}
