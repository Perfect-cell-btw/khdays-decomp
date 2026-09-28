typedef void *(*ExitTaskState)(void);
typedef struct Ov005ExitTask {
    unsigned receivedPlayerMask;
    int protocolPhase,completionStatus;
    unsigned short sendResult;
    char hostMessage[22];
} Ov005ExitTask;
extern Ov005ExitTask *NNSi_FndGetCurrentRootHeap(void);
extern unsigned Session_PackConnectedPlayerMask(void);
extern const char *data_ov005_0205b79c[3];
extern void strcpy(char *,const char *);
extern unsigned func_02031384(int,const void *,unsigned);
extern unsigned MsgQueue_SendGate(int,const void *,unsigned);
extern void *Ov005_WaitExitDelivery(void);
ExitTaskState Ov005_UpdateHostExit(void) {
    Ov005ExitTask *task=NNSi_FndGetCurrentRootHeap();
    ExitTaskState nextState=0;
    if(task->receivedPlayerMask==Session_PackConnectedPlayerMask()) {
        strcpy(task->hostMessage,data_ov005_0205b79c[0]);
        task->sendResult=func_02031384(19,task->hostMessage,22);
        task->protocolPhase=1;
        nextState=Ov005_WaitExitDelivery;
    } else {
        strcpy(task->hostMessage,data_ov005_0205b79c[1]);
        MsgQueue_SendGate(19,task->hostMessage,22);
    }
    return nextState;
}
