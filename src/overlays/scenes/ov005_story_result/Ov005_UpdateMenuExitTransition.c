typedef unsigned char u8;
typedef unsigned short u16;
/* Codegen view of the existing Ov002DayClock global; +2 is set for the next scene. */
typedef struct SceneTransition {u8 flags,submode;u16 transitionValue,parameter;} SceneTransition;
typedef struct ModeSource {char opaque[8];int mode;} ModeSource;
extern u16 data_0204c190;
extern SceneTransition data_0204c240;
extern u8 data_0204c300[];
extern ModeSource *data_ov005_0205b808;
extern int Ov005_SubScene_IsIdle(void);
extern int Ov005_SubScene_IsState2(void);
extern int Ov005_SubScene_GetResult(void);
extern int Ov005_IsState6(void);
extern int Ov005_GetResult(void);
extern void Ov005_SetField4C2C(int);
extern void Ov005_SubScene_SetFlagC60(void);
extern void Ov005_SubScene_SetFlagC5C(void);
extern void Ov005_SubScene_Arm(void);
extern void Ov005_Arm(void);
extern void Ov005_ClampEquippedItemCounts(void);
extern void PartyState_ResetBuffers(void);
extern void Ov005_ResetPartyMemberAndLayout(int,int);
extern void Scene_RequestPending(int,int);
extern void func_020235bc(int);
extern void GameState_SetFlag(int);
extern unsigned int GameState_GetField(unsigned int,unsigned int);
int Ov005_UpdateMenuExitTransition(void) {
    int result=0;
    if(Ov005_SubScene_IsIdle())Ov005_SetField4C2C(0);
    else Ov005_SetField4C2C(1);
    if(Ov005_SubScene_IsIdle() && ((data_0204c190&1)||(data_0204c190&2)))Ov005_SubScene_SetFlagC60();
    if(Ov005_SubScene_IsIdle() && (data_0204c190&8))Ov005_SubScene_SetFlagC5C();
    if(Ov005_SubScene_IsState2() && Ov005_IsState6()) {
        Ov005_SubScene_Arm();
        Ov005_Arm();
    }
    if(Ov005_SubScene_GetResult() && Ov005_GetResult()) {
        Ov005_ClampEquippedItemCounts();
        PartyState_ResetBuffers();
        Ov005_ResetPartyMemberAndLayout(0,0);
        if(data_0204c240.flags&4)Scene_RequestPending(0x13,0);
        else if((data_0204c240.flags&2)||(data_0204c240.flags&1)||(data_0204c300[0x4c]&1)) {
            func_020235bc(0x18ae);
            if(data_0204c240.flags&2)GameState_SetFlag(0x18c9);
            else if(data_0204c240.flags&1)GameState_SetFlag(0x18bd);
            data_0204c240.transitionValue=GameState_GetField(0,9)==0x165?10001:10000;
            data_0204c240.parameter=0;
            data_0204c240.submode=0;
            data_0204c240.flags=0;
            Scene_RequestPending(2,0);
        } else {
            int mode=data_ov005_0205b808->mode;
            if(mode!=999) {
                int day=GameState_GetField(0,9);
                if(day>=7 && day<=13)Scene_RequestPending(10,mode);
                else Scene_RequestPending(5,mode);
            } else Scene_RequestPending(13,0);
        }
        result=-2;
    }
    return result;
}
