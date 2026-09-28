extern void ZeroHalfThenFree(void *);
void Ov008_FreeMsgBlock(char *arg0)
{
    ZeroHalfThenFree(*(void **)(arg0 + 0x1b4));
}
