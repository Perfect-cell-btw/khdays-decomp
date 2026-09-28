/* Clears the state word of one ov057 sequence record; the actor parameter is unused. */

void Ov057_ResetSequenceState(void *unused, void *self)
{
    *(int *)self = 0;
}
