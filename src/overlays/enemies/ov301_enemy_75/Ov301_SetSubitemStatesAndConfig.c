extern void SetSubitemState(void *obj, int state, short subitem, int value);
extern void RefreshObjectCallbacks(void *obj, int value);

void Ov301_SetSubitemStatesAndConfig(int obj, int subitem, int value)
{
    SetSubitemState(*(void **)(obj + 0x384), 2, subitem, value);
    SetSubitemState(*(void **)(obj + 0x384), 0, subitem, value);
    RefreshObjectCallbacks(*(void **)(obj + 0x384), 0);
}
