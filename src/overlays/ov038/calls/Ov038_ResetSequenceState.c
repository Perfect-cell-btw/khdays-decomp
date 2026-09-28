/* Clears the state word of one ov057 sequence record; the actor parameter is unused. */

void Ov038_ResetSequenceState(void *unused, void *self)
{
    *(int *)self = 0;
}
