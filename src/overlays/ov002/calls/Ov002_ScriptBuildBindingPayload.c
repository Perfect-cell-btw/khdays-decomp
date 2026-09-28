/* Ov002_ScriptBuildBindingPayload: expand tagged script operands into binding words. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct ScriptVmOperand {u16 nType,pad2;u32 nValue;} ScriptVmOperand;
extern int ScriptVm_ReadOperandInt(void *,ScriptVmOperand *);
extern int ScriptVm_ReadOperandFx32(void *,ScriptVmOperand *);
extern u32 Ov002_List_ScaleEntryTag(u8,u16);
extern void Ov002_DriveBinding(int,int,u32 *,int);
extern int Ov002_ClaimSlotSeat(int,void *);
extern int Ov002_ResolveActorIfSlotBound(int);
int Ov002_ScriptBuildBindingPayload(void *pVm,ScriptVmOperand *pOperands)
{
    u32 aPayloadWords[128];
    int nComponent,nId,nArg,nOperandCount,nWords,nOperand; ScriptVmOperand *pValues;
    nId=ScriptVm_ReadOperandInt(pVm,pOperands);
    nArg=ScriptVm_ReadOperandInt(pVm,pOperands+1);
    nOperandCount=ScriptVm_ReadOperandInt(pVm,pOperands+2);
    nWords=0;
    nOperand=0;
    pValues=pOperands+3;
    while(nOperand<nOperandCount){
        switch(ScriptVm_ReadOperandInt(pVm,pValues+nOperand++)){
        case 0:
            for(nComponent=0;nComponent<3;nComponent++){aPayloadWords[nWords]=ScriptVm_ReadOperandFx32(pVm,pValues+nOperand++);nWords++;}
            break;
        case 1:{
            int nTable=ScriptVm_ReadOperandInt(pVm,pValues+nOperand++);
            int nIndex=ScriptVm_ReadOperandInt(pVm,pValues+nOperand++);
            if(nTable==-1 && nIndex==-1)aPayloadWords[nWords]=0;
            else aPayloadWords[nWords]=Ov002_List_ScaleEntryTag((u8)nTable,(u16)nIndex);
            nWords++;
            break;
        }
        case 2:aPayloadWords[nWords]=ScriptVm_ReadOperandInt(pVm,pValues+nOperand++);nWords++;break;
        case 3:aPayloadWords[nWords]=ScriptVm_ReadOperandFx32(pVm,pValues+nOperand++);nWords++;break;
        case 4:((int (**)(int,void *))aPayloadWords)[nWords]=Ov002_ClaimSlotSeat;nWords++;break;
        case 5:((int (**)(int))aPayloadWords)[nWords]=Ov002_ResolveActorIfSlotBound;nWords++;break;
        }
    }
    for(nOperand=0;nOperand<nWords;nOperand++){}
    Ov002_DriveBinding(nId,nArg,aPayloadWords,nOperand*4);
    return 1;
}
