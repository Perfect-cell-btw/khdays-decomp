/* Publish a state change. In a live session it goes out as a link message --
 * kind 0x15 from the host, 0x14 from a client -- and an unassigned reply
 * (0xffff) reports failure. Outside a session it is posted locally as event
 * data instead. Reports 1 unless the link request came back unassigned. */
extern int Session_IsActive(void);
extern int Session_GetLocalPlayerIndex(void);
extern int Ov002_BuildSessionCommand(int kind, void *message);
extern void GameState_SetField(int a, int b, unsigned int c);

int Ov002_PublishStateChange(int a, int b, int c) {
    unsigned char message[8];

    if (Session_IsActive() != 0) {
        *(short *)(message + 2) = (short)a;
        message[4] = (unsigned char)b;
        *(short *)(message + 6) = (short)c;

        if (Ov002_BuildSessionCommand(Session_GetLocalPlayerIndex() == 0 ? 0x14 : 0x15, message) == 0xffff) {
            return 0;
        }
    } else {
        GameState_SetField(a, b, (unsigned short)c);
    }

    return 1;
}
