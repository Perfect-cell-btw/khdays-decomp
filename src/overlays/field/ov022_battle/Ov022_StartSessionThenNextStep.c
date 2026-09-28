/* Runs the frame and, once the scene is idle, broadcasts the current cue, marks the context state
 * and disables the sound listeners; returns the gameplay hub step. */

extern void Ov022_SetActorInputEnabled(int a);
extern int Ov002_Scene_IsIdle(void);
extern int Ov022_GetGlobalPlus4(void);
extern int QueryActiveStateOrDelegate(void);
extern void Ov022_BroadcastCue(int state, int id, int obj, int a);
extern void func_ov022_0208872c(int a);
extern void SoundMgr_SetListenersEnabled(int a);
extern void Ov022_StateGameplayHub(void);
extern int data_0204be04;
extern int data_ov022_020b2e60;

struct Fld02083878 { unsigned short _lo : 3; unsigned short id : 13; };

int Ov022_StartSessionThenNextStep(void) {
    int r = 0;
    if (*(unsigned char *)&data_0204be04 != 0) return r;
    Ov022_SetActorInputEnabled(1);
    if (Ov002_Scene_IsIdle() != 0) {
        int obj = Ov022_GetGlobalPlus4();
        Ov022_BroadcastCue(QueryActiveStateOrDelegate(),
                            ((struct Fld02083878 *)(obj + 0xc))->id,
                            obj,
                            *(unsigned short *)(obj + 0xe));
        func_ov022_0208872c(1);
        *(signed char *)(data_ov022_020b2e60 + 0x3e) = 2;
        SoundMgr_SetListenersEnabled(0);
        r = (int)Ov022_StateGameplayHub;
    }
    return r;
}
