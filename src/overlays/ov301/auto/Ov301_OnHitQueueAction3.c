/* On-hit handler: queues action 3; returns 1. */

int Ov301_OnHitQueueAction3(int *r0)
{
    int *p = (int *)r0[0x214 / 4];
    *(signed char *)(*(int *)p + 0x1c7) = 3;
    return 1;
}
