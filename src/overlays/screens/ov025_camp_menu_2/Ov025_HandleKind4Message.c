/* Handle a kind-4 link message: the low halfword of the first word is the
 * payload and the high halfword selects what to do with it -- 1 forwards it to
 * the slot handler, 2 just refreshes. Anything else is ignored, and so is any
 * message of another kind (the context is still fetched first, unconditionally). */
extern int Ov025_GetPageB(void *message);
extern void Ov025_MissionListSelectRow(int ctx, int payload, int flags);
extern void Ov025_MissionList_Confirm(int ctx);

void Ov025_HandleKind4Message(unsigned int *message, int kind) {
    int ctx = Ov025_GetPageB(message);

    if (kind != 4) {
        return;
    }

    {
        unsigned int word = *(unsigned int *)message;

        switch ((unsigned short)(word >> 16)) {
        case 1:
            Ov025_MissionListSelectRow(ctx, (unsigned short)word, 0);
            break;

        case 2:
            Ov025_MissionList_Confirm(ctx);
            break;
        }
    }
}
