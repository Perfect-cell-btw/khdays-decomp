void Ov012_TileTextRenderer_SetReady(void *self, int value)
{
    *(int *)((char *)self + 0x70) = value;
}
