/* Returns the word the object's indexed pointer points to, or 0 when the pointer is NULL. */

int Obj_GetIndirectWord(int *r0, int r1)
{
    int *p = ((int **)(r0 + r1))[2];
    if (p != 0)
        return *p;
    return 0;
}
