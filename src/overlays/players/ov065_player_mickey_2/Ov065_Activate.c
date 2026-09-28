/* Activates the object: sets its active word (+0x110) and clears its timer (+0x114). */

void Ov065_Activate(void *unused, void *self)
{
    *(int *)((char *)self + 0x114) = 0;
    *(int *)((char *)self + 0x110) = 1;
}
