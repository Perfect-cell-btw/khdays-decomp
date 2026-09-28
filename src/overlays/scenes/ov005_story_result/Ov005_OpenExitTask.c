typedef unsigned char u8;
typedef void *(*ExitTaskState)(void);
typedef struct Ov005ExitTask {
    unsigned receivedPlayerMask;
    int protocolPhase,completionStatus;
    unsigned short sendResult;
    char hostMessage[22];
    struct { u8 playerIndex; char text[22]; } clientMessage;
    u8 unknown3b;
} Ov005ExitTask;
extern Ov005ExitTask *data_ov005_0205b8d0;
extern Ov005ExitTask *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *,int,unsigned);
extern unsigned Session_GetLocalPlayerIndex(void);
extern void *Ov005_UpdateClientExit(void),*Ov005_UpdateHostExit(void);
extern void Ov005_ReceiveExitMessage(const void *,int);
extern void StoreGlobalPtrArray4At0c(int,void (*)(const void *,int));
ExitTaskState Ov005_OpenExitTask(void) {
    Ov005ExitTask *task=NNSi_FndGetCurrentRootHeap();
    ExitTaskState nextState;
    data_ov005_0205b8d0=task;
    task->completionStatus=0;
    MI_CpuFill8(task->hostMessage,0,22);
    MI_CpuFill8(&task->clientMessage,0,23);
    task->clientMessage.playerIndex=Session_GetLocalPlayerIndex();
    task->protocolPhase=0;
    if(Session_GetLocalPlayerIndex()==0) {
        task->receivedPlayerMask=1;
        nextState=Ov005_UpdateHostExit;
    } else {
        task->receivedPlayerMask=0;
        nextState=Ov005_UpdateClientExit;
    }
    StoreGlobalPtrArray4At0c(19,Ov005_ReceiveExitMessage);
    return nextState;
}
