/* Returns the per-frame step byte of the stream's header. */

unsigned char MobiClip_GetStreamStepDelta(int ****p)
{
    int **q = (int **)(**p);
    return ((unsigned char *)(q[2]))[1];
}
