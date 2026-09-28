/* Frees the stack allocation and returns the argument. */

extern void StackAlloc_FreeIfSetB(void);

int Ov024_FreeStackAllocPassthrough(int a)
{
    StackAlloc_FreeIfSetB();
    return a;
}
