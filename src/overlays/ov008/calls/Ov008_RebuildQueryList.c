extern void Ov008_DestroyAllListObjects_2(void *);
extern void Ov008_QueryFieldBySelector(void *, int, int);
void Ov008_RebuildQueryList(char *obj, int value)
{
    Ov008_DestroyAllListObjects_2(obj);
    Ov008_QueryFieldBySelector(obj, *(int *)(obj + 0xc), value);
}
