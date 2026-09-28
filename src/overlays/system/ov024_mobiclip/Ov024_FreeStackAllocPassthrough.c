/* Frees the stack allocation and returns the argument. */

extern void StackAlloc_FreeIfSetB(int);

int Ov024_FreeStackAllocPassthrough(int a)
{
    StackAlloc_FreeIfSetB(a);
    return a;
}
