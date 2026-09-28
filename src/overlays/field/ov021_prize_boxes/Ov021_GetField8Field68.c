/* Returns a word of the object the object's +8 points to. */

void *Ov021_GetField8Field68(void *self)
{
    return *(void **)((char *)*(void **)((char *)self + 8) + 0x68);
}
