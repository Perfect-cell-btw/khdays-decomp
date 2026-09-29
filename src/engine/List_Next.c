/* Continues an iteration: returns the next element, or NULL at the end. */

int List_Next(void *pR0)
{
    int *r0 = (int *)pR0;
    int *node;

    node = (int *)((int *)r0[9])[1];
    r0[9] = (int)node;
    if (node == r0 + 4) {
        return 0;
    }
    return node[3];
}
