void *List_Last(void *p)
{
    void **q = ((void ***)p)[4];
    ((void ***)p)[9] = q;
    if ((void *)q == p)
        return 0;
    return q[3];
}
