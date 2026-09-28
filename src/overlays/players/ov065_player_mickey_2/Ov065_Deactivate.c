/* Clears the word at +0x24 of the second argument (its timer). */

void Ov065_Deactivate(void *unused, void *self)
{
    *(int *)((char *)self + 0x110) = 0;
}
