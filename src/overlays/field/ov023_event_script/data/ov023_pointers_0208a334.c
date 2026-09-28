/* ov023 .data pointer tables, 0x0208a334-0x0208a5cc.
 *
 * 2 tables, all zero in the ROM image because every entry is a relocation;
 * a zero word is a null entry.
 */

extern void Ov023_CmdLoadActor(void);
extern void Ov023_Cmd_StartEntityMotionParam(void);
extern void Ov023_CmdPlaceActor(void);
extern void Ov023_Cmd_StopEntitySound(void);
extern void Ov023_Cmd_ParentEntityToEntity(void);
extern void Ov023_Cmd_ShowEntity(void);
extern void Ov023_Cmd_HideEntity(void);
extern void Ov023_Cmd_PlayEntityAnimKind1(void);
extern void Ov023_CmdRampActorTransition(void);
extern void Ov023_ScriptOpDispatchWrapped(void);
extern void Ov023_Cmd_SetEntityLookupValue(void);
extern void Ov023_Cmd_PlayNamedMotionOrNode(void);
extern void Ov023_ScriptCmd_StoreIfFree(void);
extern void Ov023_Cmd_TestEntityCollisionBit(void);
extern void Ov023_CmdEntry_SpawnEntityFollower(void);
extern void Ov023_CmdStoreSlot48(void);
extern void Ov023_Cmd_FaceEntityTowards(void);
extern void Ov023_CmdStoreSlot48_2(void);
extern void Ov023_Cmd_PlayEntityAnim(void);
extern void Ov023_ScriptCmd_SetCharacterEntry(void);
extern void Ov023_VmTickActor(void);
extern void Ov023_CmdStartBrightnessFade(void);
extern void Ov023_CmdStepBrightnessFade(void);
extern void Ov023_CmdResetStage(void);
extern void Ov023_CmdMoveCamera(void);
extern void Ov023_CmdStopCamera(void);
extern void Ov023_CmdStartScreenBlend(void);
extern void Ov023_CmdStepScreenBlend(void);
extern void Ov023_CmdPushVramState(void);
extern void Ov023_RebuildVisibleEntries(void);
extern void Ov023_Cmd_StartNamedMotion(void);
extern void Ov023_Cmd_EntityAction895dc(void);
extern void Ov023_VmResetRegisters(void);
extern void Ov023_VmStep(void);
extern void Ov023_Cmd_SetEntityAngles(void);
extern void Ov023_Cmd_PushEntityTween3(void);
extern void Ov023_Cmd_NudgeEntityByCamera(void);
extern void Ov023_ScriptOpStoreInt(void);
extern void Ov023_Cmd_EntityAction88f90(void);
extern void Ov023_Cmd_ResolveEntityHandle(void);
extern void Ov023_ScriptOpRunEntityAction(void);
extern void Ov023_Cmd_SetEntityScale(void);
extern void Ov023_Cmd_AttachEntityToEntity(void);
extern void Ov023_CmdSetAnchor(void);
extern void Ov023_CmdSetupPartyActors(void);
extern void Ov023_CmdAttachWeapons(void);
extern void Ov023_Cmd_EntityAction88f08(void);
extern void Ov023_ScriptOpRunEntityTablePass(void);
extern void Ov023_CmdPlayCameraScript(void);
extern void Ov023_VmSetSlotPairAndMode(void);
extern void Ov023_Cmd_ClearEntityOffsetY(void);
extern void Ov023_CmdPlaceObject(void);
extern void Ov023_ScriptCmd_SetEventFlag(void);
extern void Ov023_CmdSetEventFlag(void);
extern void Ov023_CmdSetCamera(void);
extern void Ov023_ScriptOpStoreSlotFx32(void);
extern void Ov023_Cmd_WriteEntityField(void);
extern void Ov023_CmdPlaceRelative(void);
extern void Ov023_Cmd_SetEntityTransformA(void);
extern void Ov023_Cmd_EntityAction89174(void);
extern void Ov023_CmdWarpActor(void);
extern void Ov023_CmdStoreGlobalValue(void);
extern void Ov023_Cmd_SetEntityFlag(void);
extern void Ov023_Cmd_PlayEntityAnimByName(void);
extern void Ov023_CmdActorSpeak(void);
extern void Ov023_Cmd_StartEntityMotion(void);
extern void Ov023_Cmd_SeekEntityAnim(void);
extern void Ov023_CmdRampAnimFrame(void);
extern void Ov023_VmWaitRecordIdle(void);
extern void Ov023_ScriptOpTestSlot(void);
extern void Ov023_Cmd_SetEntityTransformB(void);
extern void Ov023_CmdSeatMembers(void);
extern void Ov023_Cmd_EntityAction8929c(void);
extern void Ov023_Cmd_SetEntitySlot(void);
extern void Ov023_CmdOpenDialog(void);
extern void Ov023_CmdWaitDialog(void);
extern void Ov023_ScriptOpActWhenOpcodeC(void);
extern void Ov023_ScriptTestOpcodeC(void);
extern void Ov023_CmdWaitScriptIdle(void);
extern void Ov023_Cmd_WorldActionAtEntity(void);
extern int data_ov023_0208a1a4;
extern int data_ov023_0208a1b8;
extern int data_ov023_0208a1cc;
extern int data_ov023_0208a1e0;
extern int data_ov023_0208a1f4;
extern int data_ov023_0208a208;
extern int data_ov023_0208a21c;
extern int data_ov023_0208a230;
extern int data_ov023_0208a244;
extern int data_ov023_0208a258;
extern int data_ov023_0208a26c;
extern int data_ov023_0208a280;
extern int data_ov023_0208a294;
extern int data_ov023_0208a2a8;
extern int data_ov023_0208a2bc;
extern int data_ov023_0208a2d0;
extern int data_ov023_0208a2e4;
extern int data_ov023_0208a2f8;
extern int data_ov023_0208a30c;
extern int data_ov023_0208a320;

void *data_ov023_0208a334[20] = {

    &data_ov023_0208a320,

    &data_ov023_0208a208,

    &data_ov023_0208a21c,

    &data_ov023_0208a230,

    &data_ov023_0208a244,

    &data_ov023_0208a1b8,

    &data_ov023_0208a2e4,

    &data_ov023_0208a258,

    &data_ov023_0208a26c,

    &data_ov023_0208a280,

    &data_ov023_0208a294,

    &data_ov023_0208a2a8,

    &data_ov023_0208a2bc,

    &data_ov023_0208a2d0,

    &data_ov023_0208a2f8,

    &data_ov023_0208a30c,

    &data_ov023_0208a1cc,

    &data_ov023_0208a1e0,

    &data_ov023_0208a1a4,

    &data_ov023_0208a1f4,

};

void *data_ov023_0208a384[146] = {

    (void *)Ov023_CmdLoadActor,

    0,

    (void *)Ov023_Cmd_StartEntityMotionParam,

    0,

    (void *)Ov023_CmdPlaceActor,

    0,

    (void *)Ov023_Cmd_StopEntitySound,

    0,

    (void *)Ov023_Cmd_ParentEntityToEntity,

    0,

    (void *)Ov023_Cmd_ShowEntity,

    0,

    (void *)Ov023_Cmd_HideEntity,

    0,

    (void *)Ov023_Cmd_PlayEntityAnimKind1,

    (void *)Ov023_CmdRampActorTransition,

    (void *)Ov023_ScriptOpDispatchWrapped,

    0,

    (void *)Ov023_Cmd_SetEntityLookupValue,

    0,

    (void *)Ov023_Cmd_PlayNamedMotionOrNode,

    0,

    (void *)Ov023_ScriptCmd_StoreIfFree,

    (void *)Ov023_Cmd_TestEntityCollisionBit,

    (void *)Ov023_CmdEntry_SpawnEntityFollower,

    0,

    (void *)Ov023_CmdStoreSlot48,

    (void *)Ov023_Cmd_FaceEntityTowards,

    (void *)Ov023_CmdStoreSlot48_2,

    (void *)Ov023_Cmd_PlayEntityAnim,

    (void *)Ov023_ScriptCmd_SetCharacterEntry,

    0,

    (void *)Ov023_VmTickActor,

    0,

    (void *)Ov023_CmdStartBrightnessFade,

    (void *)Ov023_CmdStepBrightnessFade,

    (void *)Ov023_CmdResetStage,

    0,

    (void *)Ov023_CmdMoveCamera,

    0,

    0,

    0,

    0,

    0,

    (void *)Ov023_CmdStopCamera,

    0,

    0,

    0,

    (void *)Ov023_CmdStartScreenBlend,

    (void *)Ov023_CmdStepScreenBlend,

    (void *)Ov023_CmdPushVramState,

    0,

    (void *)Ov023_RebuildVisibleEntries,

    0,

    (void *)Ov023_Cmd_StartNamedMotion,

    0,

    (void *)Ov023_Cmd_EntityAction895dc,

    0,

    (void *)Ov023_VmResetRegisters,

    (void *)Ov023_VmStep,

    (void *)Ov023_Cmd_SetEntityAngles,

    0,

    (void *)Ov023_Cmd_PushEntityTween3,

    (void *)Ov023_Cmd_NudgeEntityByCamera,

    (void *)Ov023_ScriptOpStoreInt,

    0,

    (void *)Ov023_Cmd_EntityAction88f90,

    0,

    (void *)Ov023_Cmd_ResolveEntityHandle,

    (void *)Ov023_ScriptOpRunEntityAction,

    (void *)Ov023_Cmd_SetEntityScale,

    0,

    (void *)Ov023_Cmd_AttachEntityToEntity,

    0,

    (void *)Ov023_CmdSetAnchor,

    0,

    (void *)Ov023_CmdSetupPartyActors,

    0,

    (void *)Ov023_Cmd_EntityAction88f08,

    0,

    (void *)Ov023_ScriptOpRunEntityTablePass,

    0,

    (void *)Ov023_CmdPlayCameraScript,

    0,

    (void *)Ov023_VmSetSlotPairAndMode,

    0,

    (void *)Ov023_Cmd_ClearEntityOffsetY,

    0,

    (void *)Ov023_CmdPlaceObject,

    0,

    (void *)Ov023_ScriptCmd_SetEventFlag,

    0,

    (void *)Ov023_CmdSetEventFlag,

    0,

    (void *)Ov023_CmdSetCamera,

    0,

    (void *)Ov023_ScriptOpStoreSlotFx32,

    0,

    (void *)Ov023_Cmd_WriteEntityField,

    0,

    (void *)Ov023_CmdPlaceRelative,

    0,

    (void *)Ov023_Cmd_SetEntityTransformA,

    0,

    (void *)Ov023_Cmd_EntityAction89174,

    0,

    (void *)Ov023_CmdWarpActor,

    0,

    0,

    0,

    (void *)Ov023_CmdStoreGlobalValue,

    0,

    0,

    0,

    (void *)Ov023_Cmd_SetEntityFlag,

    0,

    (void *)Ov023_CmdAttachWeapons,

    0,

    (void *)Ov023_Cmd_PlayEntityAnimByName,

    (void *)Ov023_CmdActorSpeak,

    (void *)Ov023_Cmd_StartEntityMotion,

    0,

    (void *)Ov023_Cmd_SeekEntityAnim,

    (void *)Ov023_CmdRampAnimFrame,

    (void *)Ov023_VmWaitRecordIdle,

    (void *)Ov023_ScriptOpTestSlot,

    (void *)Ov023_Cmd_SetEntityTransformB,

    0,

    (void *)Ov023_CmdSeatMembers,

    0,

    (void *)Ov023_Cmd_EntityAction8929c,

    0,

    0,

    0,

    (void *)Ov023_Cmd_SetEntitySlot,

    0,

    0,

    0,

    (void *)Ov023_CmdOpenDialog,

    (void *)Ov023_CmdWaitDialog,

    (void *)Ov023_ScriptOpActWhenOpcodeC,

    0,

    (void *)Ov023_ScriptTestOpcodeC,

    (void *)Ov023_CmdWaitScriptIdle,

    (void *)Ov023_Cmd_WorldActionAtEntity,

    0,

};
