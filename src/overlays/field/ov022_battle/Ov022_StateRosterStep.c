/* Roster state: runs the frame and, once the scene is idle, either starts the session or applies
 * the roster result (records the world, posts the result link message, fires the slot hooks, clears
 * the lists and releases the link collections) and picks the next state. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef void *(*Ov022StateCallback)(void);

typedef struct Ov022Context {
    u16 flags;
    char pad_0002[0x2e];
    int sessionHandle;
} Ov022Context;

typedef struct Ov022Entity {
    char pad_0000[0x2668];
    void *pendingObject;
} Ov022Entity;

extern u8 data_0204be04;
extern u8 data_0204c240;
extern Ov022Context *data_ov022_020b2e60;

extern void Ov022_SetActorInputEnabled(int mode);
extern int Ov002_Scene_IsIdle(void);
extern int QueryActiveStateOrDelegate(void);
extern int func_ov022_020886d0(int index);
extern int Ov002_GetSignedByteAt2(int handle);
extern void GameState_SetField(int field, int width, int value);
extern int Ov002_GetBit0OfByte0(int handle);
extern void Ov002_FormatWorldPath(int handle, void *payload);
extern int Ov002_GetCodeOwnerSlot(int handle);
extern int Ov002_GetSignedByteAt3(int handle);
extern int Ov002_GetSignedByteAt1(int handle);
extern void Ov002_PostResultLinkMessage(int slot, void *payload, int argument, int flag);
extern Ov022Entity *GetEntryField20ByIndex(int index);
extern int Ov022_GetEntryField66(int index);
extern void Ov002_FireSlotHook(int index, int argument);
extern void Ov002_SetCurrentSlotFlag1(int enabled);
extern void Ov002_Field_ClearWord9C(void);
extern void Ov002_ReadRosterSeat(int index, int *outKind, int *outSlot);
extern void Ov002_ClearListB(int index);
extern void Ov002_ReleaseLinkCollections(void);

extern void *Ov022_StartSessionThenNextStep(void);
extern void *Ov022_StateGameplayHub(void);
extern void *func_ov022_020836f8(void);

Ov022StateCallback Ov022_StateRosterStep(void)
{
    char payload[12];
    int rosterSlot;
    Ov022StateCallback next = 0;

    if (data_0204be04 != 0) {
        return next;
    }

    Ov022_SetActorInputEnabled(1);
    if (Ov002_Scene_IsIdle() != 0) {
        if (func_ov022_020886d0(QueryActiveStateOrDelegate()) != 0) {
            return Ov022_StartSessionThenNextStep;
        }

        if ((data_0204c240 & 4) == 0 &&
            Ov002_GetSignedByteAt2(data_ov022_020b2e60->sessionHandle) < 0x100) {
            GameState_SetField(
                0x2099,
                8,
                (u16)Ov002_GetSignedByteAt2(data_ov022_020b2e60->sessionHandle));
        }

        if (Ov002_GetBit0OfByte0(data_ov022_020b2e60->sessionHandle) != 0) {
            int slot;
            int argument;
            int flag;

            Ov002_FormatWorldPath(data_ov022_020b2e60->sessionHandle, payload);
            slot = Ov002_GetCodeOwnerSlot(data_ov022_020b2e60->sessionHandle);
            argument = Ov002_GetSignedByteAt3(data_ov022_020b2e60->sessionHandle);
            flag = Ov002_GetSignedByteAt1(data_ov022_020b2e60->sessionHandle);
            Ov002_PostResultLinkMessage(slot, payload, argument, flag);

            data_ov022_020b2e60->sessionHandle = 0;
            GetEntryField20ByIndex(QueryActiveStateOrDelegate())->pendingObject = 0;
            data_ov022_020b2e60->flags |= 0x80;
            return Ov022_StateGameplayHub;
        }

        Ov002_FireSlotHook(Ov022_GetEntryField66(QueryActiveStateOrDelegate()), 0);
        Ov002_SetCurrentSlotFlag1(0);
        Ov002_Field_ClearWord9C();
        Ov002_ReadRosterSeat(Ov022_GetEntryField66(QueryActiveStateOrDelegate()), 0, &rosterSlot);
        Ov002_ClearListB((u16)rosterSlot);
        Ov002_ReleaseLinkCollections();
        next = func_ov022_020836f8;
    }

    return next;
}
