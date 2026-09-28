/* Ov002_ScriptOpenChoicePanel: decode script text and submit a choice request. */

#include "nitro/types.h"

typedef struct ScriptVmOperand {u16 nType,pad2;u32 nValue;} ScriptVmOperand;
typedef struct Ov002PanelChoiceFields {u16 *pTitle,*apChoices[3];int nFlags,nSelection,nMode;} Ov002PanelChoiceFields;
typedef union Ov002PanelRequestPayload {int aWords[7];Ov002PanelChoiceFields choice;} Ov002PanelRequestPayload;
typedef struct Ov002PanelRequest {Ov002PanelRequestPayload payload;int nRequestType,nReserved;} Ov002PanelRequest;
extern char *ByteCode_ResolveOperand(void *,ScriptVmOperand *);
extern int ScriptVm_ReadOperandInt(void *,ScriptVmOperand *);
extern int Ov002_GetPhaseWord(void);
extern u8 data_0204c240;
extern void Utf8_ToUcs2(char *,u16 *);
extern void Ov002_SetSeatFlag(int,int);
extern void Ov002_ClearCurrentCaption(void);
extern int Ov002_TryBeginPanelRequest(Ov002PanelRequest *,int);
extern void Ov002_TakeBattleViewFocus(void);
extern void GameState_SetField(int,int,int);
int Ov002_ScriptOpenChoicePanel(void *pVm,ScriptVmOperand *pOperands)
{
    u16 aTitleText[256],aChoiceText0[256],aChoiceText1[256],aChoiceText2[256];
    Ov002PanelRequest request;
    int aSeatFlags[3];
    char *apChoiceText[3];
    int i;
    char *pTitle;
    int nMode,nChoices;
    ScriptVmOperand *pCurrent;
    pTitle=ByteCode_ResolveOperand(pVm,pOperands);
    nMode=ScriptVm_ReadOperandInt(pVm,pOperands+1);
    pCurrent=pOperands+2;
    pOperands+=3;
    nChoices=ScriptVm_ReadOperandInt(pVm,pCurrent);
    if(Ov002_GetPhaseWord()==1 && (data_0204c240&4))return 1;
    for(i=0;i<nChoices;i++){
        apChoiceText[i]=ByteCode_ResolveOperand(pVm,pOperands);
        pCurrent=pOperands+1;
        pOperands+=2;
        aSeatFlags[i]=ScriptVm_ReadOperandInt(pVm,pCurrent);
    }
    Utf8_ToUcs2(pTitle,aTitleText);
    request.payload.choice.pTitle=aTitleText;
    request.payload.choice.apChoices[0]=request.payload.choice.apChoices[1]=request.payload.choice.apChoices[2]=0;
    request.payload.choice.nFlags=0;
    request.payload.choice.nSelection=-1;
    request.payload.choice.nMode=nMode;
    if(nChoices>0){Utf8_ToUcs2(apChoiceText[0],aChoiceText0);request.payload.choice.apChoices[0]=aChoiceText0;}
    if(nChoices>1){Utf8_ToUcs2(apChoiceText[1],aChoiceText1);request.payload.choice.apChoices[1]=aChoiceText1;}
    if(nChoices>2){Utf8_ToUcs2(apChoiceText[2],aChoiceText2);request.payload.choice.apChoices[2]=aChoiceText2;}
    Ov002_SetSeatFlag(0,aSeatFlags[0]);
    Ov002_SetSeatFlag(1,aSeatFlags[1]);
    Ov002_SetSeatFlag(2,aSeatFlags[2]);
    Ov002_ClearCurrentCaption();
    Ov002_TryBeginPanelRequest(&request,0);
    Ov002_TakeBattleViewFocus();
    GameState_SetField(0x20ef,1,1);
    return 0;
}
