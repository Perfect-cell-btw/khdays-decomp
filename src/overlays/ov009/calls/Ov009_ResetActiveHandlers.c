extern int data_ov009_020563ec[];

void Ov009_ResetActiveHandlers(void)
{
    if (data_ov009_020563ec[0] != -1) {
        data_ov009_020563ec[0] = -1;
    }

    if (data_ov009_020563ec[1] != -1) {
        data_ov009_020563ec[1] = -1;
    }
}
