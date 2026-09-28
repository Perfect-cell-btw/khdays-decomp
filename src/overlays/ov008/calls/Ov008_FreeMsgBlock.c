/* Frees the object's message block (+0x1b4). */

extern void ZeroHalfThenFree(void *);
void Ov008_FreeMsgBlock(char *arg0)
{
    ZeroHalfThenFree(*(void **)(arg0 + 0x1b4));
}
